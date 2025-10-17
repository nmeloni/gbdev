# Hello Sprite

- On crée un ensemble de sprite de caractères avec **GBTD**
 <img src="https://github.com/nmeloni/gbdev/blob/main/img/GBTD-alpha.png" alt="GBRD" width="300" title="Sprite de lettre avec GBTD"/>

- On inclut le fichier `alphabet.h` et on charge les sprites avec la fonction  `set_sprite_data(0,28,alphabet)` où 0 et 28 correspondent respectivement à l'adresse en VRAM où sera placé le premier sprite et au nombre de sprites à charger depuis le pointeur `alphabet`

- La gameboy ne peut afficher que 10 sprites par *scanline*. Le texte
  comporte 11 caractères et autant de sprites. En décalant un
  caractère vers le haut on peut ainsi tous les afficher.

<img src="https://github.com/nmeloni/gbdev/blob/main/img/helloworld.gif" alt="HW" width="300" title="Hello World animé"/>
