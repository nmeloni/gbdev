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

