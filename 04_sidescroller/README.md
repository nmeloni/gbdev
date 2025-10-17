# Side scroller

La gestion des arrière-plans (*background*) est constituée de deux étapes:
- le chargement en mémoire d'un ensemble de tuiles composant le décors (`background data`)

<img src="https://github.com/nmeloni/gbdev/blob/main/img/gb_tilemap.png" alt="tilemap" width="300" title="Tilemap"/>

- un tableau représentant l'ensemble des cases de la mémoire vidéos
  découpé en carrés de 8x8 pixels faisant correspondre à chaque carré
  une tuile (`background map`)
  
L'effet de scrolling est en fait un déplacement de la "*caméra*"
interne de la Gameboy dans la mémoire vidéo.


  <img src="https://github.com/nmeloni/gbdev/blob/main/img/sidescroller.gif" alt="scidescroller" width="300" title="Scrolling Background"/> <img src="https://github.com/nmeloni/gbdev/blob/main/img/sidescrollervram.gif" alt="vram" width="300" title="Scrolling Background from VRAM"/>



