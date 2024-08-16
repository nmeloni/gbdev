# MOUVEMENTS

Le déplacement d'un objet à l'écran permet de mettre en place
plusieurs concepts important pour la programmation d'un jeu:

- la gestion d'un objet constitué d'un ou plusieurs sprites
- l'animation sur plusieurs frame des différents objets
- la physique des mouvements
- la gestion des collisions entre objets

# Metasprites

**GBDK-2020** fourni un outils permettant de convertir un fichier
**.png** en *metasprites*. Ceux-ci peuvent être manipulés directement
via des fonctions *ah-hoc*.

Dans cet exemple on crée un fichier 16x64 pixels contenant les différentes sprites de *Carti*

<img src="https://github.com/nmeloni/gbdev/blob/main/img/cartisheet.png" alt="cartisheet" width="500" title="Un exemple de sprite sheet"/>

La *sprite sheet* est convertie à l'aide de la commande

``` bash
png2asset cartisheet.png -c carti.c -sw 16 -sh 16 -spr8x8 
```

Les paramètres précisent que l'image est constituée de metasprites de
largeur (`-sw`) et hauteur (`-sh`) de 16 pixels. L'option `-spr8x8`
précise que chaque metasprite est géré en mode 8x8 pixel (la Gameboy
autorise également un mode 8x16).

# Animation

Dans cet exemple seule la course est animée en 2 images (*metasprites*
1 et 2). On utilise un compteur de frame (champ `.runframe` de la
structure `entity`) et on change le sprite de déplacement en fonction
du troisième bit pour une animation pas trop nerveuse.

# Physique

Le positionnement à l'écran est géré avec la méthode des
*subpixels*. Cela consiste à utiliser des entiers de 16 bits pour
calculer une coordonnée est à ignorer, par exemple, les 4 bits de poids
faible lors du calcul du pixel correspondant (les 4 bits ignorés sont
des *sous-pixels*). L'avantage est de permettre des déplacements plus
fluides.

La gestion de la physique elle-même est standard avec une gestion de
l'accélération, de la vitesse et enfin du déplacement.

<img src="https://github.com/nmeloni/gbdev/blob/main/img/movement.gif" alt="moves" width="500" title="Un exemple de gestion des mouvements"/>
