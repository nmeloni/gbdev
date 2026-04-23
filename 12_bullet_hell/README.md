# Bullet Hell

Mini jeu d'esquive de bullets. Le but est de mettre en évidence la
forte contrainte en calcul qu'impose le développement sur Gameboy. La
gestion d'une vingtaine d'entité à l'écran nécessite de faire appel à
plusieurs techniques spécifiques qui sortent un peu des canons de
programmation classique.

## Arithmétiques 8-bits

La principale limitation du processeur Z80 de la gameboy est son
arithmétique 8-bit limitée. Pas de multiplications, de divisions ou de
modulos. Seules les opérations faisant intervenir des puissances de 2
sont efficaces.

Il est possible d'utiliser des entiers sur 16-bits (c'est notamment le
cas dans la gestion d'adresse) mais l'arithmétique est alors simulée
et particulièrement lente.

Conséquence pratique : **toutes les coordonnées, compteurs et flags
sont déclarés en `uint8_t`** afin de rester dans les registres natifs
du Z80 et éviter l'émulation 16-bits coûteuse.

## Coordonnées subpixels (virgule fixe 4 bits)

L'écran de la Gameboy fait 160×144 pixels. Les entiers 8-bits
suffisent pour afficher les sprites mais les animations seraient
saccadées si chaque entité avançait d'un pixel entier par frame.

On utilise une **virgule fixe 4 bits** : chaque corps (`body_t`)
possède deux entiers `uint8_t` distincts pour la position entière
(`x`, `y`) et deux `int8_t` pour la partie fractionnaire (`fx`,
`fy`). La mise à jour se fait avec un décalage binaire et un masque,
sans aucune division :

```c
body->fx += body->dx;
body->x  += body->fx >> FRAC_SHIFT;  // >> 4 : pas de division
body->fx &= FRAC_MASK;               // & 0x0F : pas de modulo
```

Les vitesses sont exprimées en unités de 1/16ème de pixel par frame,
ce qui donne une plage [−8, +8] px/frame avec une résolution fine.

## Tables de lookup pour les directions

Calculer `sin()` / `cos()` est impossible en temps réel sur le Z80 :
ces fonctions n'existent pas dans le jeu d'instructions et toute
émulation en virgule flottante serait beaucoup trop lente.

À la place, on pré-calcule les composantes (dx, dy) pour
**16 directions régulières** (tous les 22,5°) et on les stocke dans
deux tableaux en ROM :

```c
const int8_t directions_dx[16] = { 16, 15, 11,  6,  0, -6, -11, -15, ... };
const int8_t directions_dy[16] = {  0, -6, -11,-15,-16,-15, -11,  -6, ... };
```

Les valeurs sont normalisées pour que la norme soit ≈ 16 subpixels,
cohérente avec le décalage de 4 bits. Affecter une direction à un
bullet se réduit à une simple lecture de tableau (O(1), coût nul).

La fonction `aimed_direction()` détermine la case de table la plus
proche uniquement avec des comparaisons et des décalages, sans aucune
opération trigonométrique.

## Pool d'entités statique et liste active

L'allocation dynamique (`malloc`) est prohibée sur GB. On utilise un
**pool statique** de taille fixe `BULLETS_POOL[MAX_BULLETS]` alloué à
la compilation.

Pour ne pas itérer sur les 24 slots à chaque frame (même les
inactifs), on maintient en parallèle une **liste compacte des indices
actifs** `ACTIVE_BULLETS[]` avec son compteur `active_bullet_count`.
La boucle de mise à jour ne visite que les bullets vivants.

La suppression est en **O(1)** grâce au swap avec le dernier élément :

```c
static inline void kill_bullet(uint8_t j) {
    BULLETS_POOL[ACTIVE_BULLETS[j]].active = 0;
    ACTIVE_BULLETS[j] = ACTIVE_BULLETS[--active_bullet_count];
}
```

L'ordre de la liste n'est pas garanti, mais cela n'a aucune importance
pour ce type de jeu.

## Boucle d'entités et pointeurs locaux

Les adresses mémoire sont sur 16 bits sur le Z80. Accéder
répétitivement à `BULLETS_POOL[i].body.x` force le compilateur à
recalculer l'adresse 16-bits à chaque accès.

Pour minimiser ce coût, on déclare un **pointeur local** sur la
structure en début de boucle. Le compilateur peut alors conserver
l'adresse dans une paire de registres :

```c
uint8_t *ab = &ACTIVE_BULLETS[0];
while (j < active_bullet_count) {
    bullet_t *b = &BULLETS_POOL[*ab];  // adresse calculée une seule fois
    update_body_position(&b->body);
    ...
    ab++; j++;
}
```

## Frame skip

L'objectif est de tourner à 60 frames par seconde, ce qui laisse très
peu de cycles pour l'ensemble des calculs d'une frame. Certains
calculs peuvent être décalés sur plusieurs frames sans impact visible.

**Vérification des bordures 1 frame sur 8** : savoir si un bullet a
quitté l'écran n'est pas critique à chaque frame (un bullet ne
traverse pas l'écran entier en une frame). On ne fait le test que
lorsque `frame_counter % 8 == 0`, économisant la condition pour les 7
autres frames.

**Collision alternée** : tester les collisions de tous les bullets
actifs à chaque frame serait trop coûteux. On alterne entre les
bullets pairs et impairs grâce à un bit qui bascule :

```c
bullet_collision_bit ^= 1;
for (uint8_t j = 0; j < active_bullet_count; j++) {
    if (j % 2 == bullet_collision_bit) continue;  // skip la moitié
    ...
}
```

Cela divise par deux le coût de la détection de collision, au prix
d'une latence d'une frame — imperceptible en pratique.

## Détection de collision en deux passes

Le test AABB complet (4 comparaisons) est relativement coûteux.
Avant de l'effectuer, on filtre les bullets trop éloignés avec la
**distance de Manhattan** (2 soustractions + 1 addition, sans racine
carrée) :

```c
if (manathan_distance(b->body.x, b->body.y, px, py) > MAN_DIST_THRESHOLD)
    continue;  // bullet trop loin, on évite l'AABB
if (check_collision_box(...))
    return 1;
```

La distance de Manhattan surestime légèrement la vraie distance, mais
elle ne génère aucun faux négatif : un bullet qui passe le seuil
est systématiquement testé en AABB. Elle écarte rapidement les bullets
distants avec un coût minimal.

## Arithmétique sans branchement (branchless)

Les instructions de branchement conditionnel (`if`) vident le pipeline
du Z80. Pour les opérations simples comme le clamp, on les remplace
par de l'arithmétique pure :

```c
// Clamp sans if : multiplication par le résultat booléen (0 ou 1)
value = value + ((min - value) * (min > value));
value = value - ((value - max) * (max < value));
```

De même, `is_inside_bounds()` utilise `&` (ET binaire) au lieu de
`&&` (ET logique avec court-circuit) pour éviter un saut conditionnel
supplémentaire.

## Gestion du underflow uint8_t

Les positions sont en `uint8_t` (non signé). Soustraire au-delà de 0
provoque un **wrap-around** vers 255 plutôt qu'une valeur négative.
Ce comportement est exploité comme sentinel : une position > 200
signale un underflow et est ramenée à la valeur minimale :

```c
if (PLAYER.body.x > 200u) PLAYER.body.x = PLAYER_MIN_X;
```

## Variation pseudo-aléatoire par XOR

Appeler `rand()` est coûteux. Pour varier la position de spawn des
bullets sans coût, on combine le compteur de frames et l'indice du
slot avec un XOR :

```c
uint8_t var = (uint8_t)(frame_counter ^ (i << 2));
```

Cette opération est instantanée et produit une distribution
suffisamment irrégulière pour le gameplay.
