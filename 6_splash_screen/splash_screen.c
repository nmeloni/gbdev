#include <gb/gb.h>
#include "alphabet.h"
#include "splashscreen.h"

#define TEXT_FONT_OFFSET 0xD0
#define TEXT_FONT_TILE_COUNT 28

#define TEXT_SPC 0xD0
#define TEXT_A   0xD1
#define TEXT_EXC 0xEB

void print_text_bkg(UINT8 x, UINT8 y, unsigned char * text);

void main(void)
{
  //On charge la font dans la mémoire bkg
  set_bkg_data(TEXT_FONT_OFFSET, TEXT_FONT_TILE_COUNT,alphabet);

  //On ecrit le texte 
  print_text_bkg(2, 8,"bonjour\ntous le monde!");
  //On place la fenetre d'affichage en dessous
  UINT8 y = 80;
  move_bkg(0,y);
  SHOW_BKG;

  //Scrolling pour affichage descendant
  while (y > 0){
    move_bkg(0,y);
    delay(50);
    y--;
  }
  //On attend 2 seconde pour un fondu blanc
  delay(2000);
  BGP_REG = 0xE4;
  delay(100);
  BGP_REG = 0x90;
  delay(200);
  BGP_REG = 0x40;
  delay(200);
  BGP_REG = 0x00;
  delay(200);

  //On charge l'écran titre
  set_bkg_data(0, splashscreen_TILE_COUNT,splashscreen_tiles);
  set_bkg_tiles(0,0,20,18,splashscreen_map);
  BGP_REG = 0xE4;

  //press start clignotant
  while (1){
    print_text_bkg(4, 14,"press  start");
    delay(1000);
    print_text_bkg(4, 14,"            ");
    delay(400);
  }
}

//Fonction dépendante de la font actuelle concernant les offset
void print_text_bkg(UINT8 X, UINT8 Y, unsigned char * text){

  //caractère a afficher, blanc par défaut;
  UINT8 letter = TEXT_SPC;
  UINT8 x=0, y=0;
  
  while (*text != '\0'){
    if (*text == ' '){
      letter = TEXT_SPC;
    } else if (*text == '!'){
      letter = TEXT_EXC;
    } else if (*text == '\n'){
      x = 0;
      y++;
      text++;
      continue;
    } else {
      letter = *text - 'a' + TEXT_A;
    }

    set_bkg_tiles(x+X,y+Y,1,1,&letter);
    x++;
    text++;
  }
  
}
