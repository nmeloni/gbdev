# AFFICHAGE DE SCORE

L'affichage d'un score est très similaire à de l'affichage de texte,
seule sa modification est un peu particulière. En effet les opérations
arithmétiques de la Gameboy telles que la division ou le modulo sont
particulièrement lente si elles n'impliquent pas des puissances
de 2. Il vaut mieux donc gérer l'arithmétique *à la main*.

Dans l'exemple proposé, la croix directionnelle permet de modifier
individuellement chaque chiffre et le bouton **A** incrémente le score
de 1.

<img src="https://github.com/nmeloni/gbdev/blob/main/img/score.gif" alt="moves" width="500" title="Affichage de score"/>
