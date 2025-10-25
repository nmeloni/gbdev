#include <gb/gb.h>
#include <stdint.h>

#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/emu_debug.h>

#include "entity.h"
#include "box.h"
#include "carti.h"

#define CARTI_TILE_OFFSET 0
#define BOX_TILE_OFFSET 16

#define UPDATE_KEYS()   previous_joypad = current_joypad; current_joypad = joypad()
#define KEY_PRESSED(K)  (current_joypad & (K))
uint8_t current_joypad, previous_joypad;

void init_gfx(void) {
    set_sprite_data(BOX_TILE_OFFSET, box_TILE_COUNT, box_tiles);
    set_sprite_data(CARTI_TILE_OFFSET, carti_TILE_COUNT, carti_tiles);
    SPRITES_8x16;
    SHOW_SPRITES;
    DISPLAY_ON;
}

void main(void)
{
    // On initialise les graphismes
    init_gfx();

    Entity box[4];
    int8_t const  box_bounding_boxes[] = {0,0,16,16 }; // Un seul bounding box de 16x16
    init_entity(&box[0], 80, 72, box_bounding_boxes, box_metasprites, BOX_TILE_OFFSET);
    init_entity(&box[1], 40, 72, box_bounding_boxes, box_metasprites, BOX_TILE_OFFSET);
    init_entity(&box[2], 40, 112, box_bounding_boxes, box_metasprites, BOX_TILE_OFFSET);
    init_entity(&box[3], 80, 112, box_bounding_boxes, box_metasprites, BOX_TILE_OFFSET);

    Entity carti;
    int8_t const  carti_bounding_boxes[] = {0,0,16,16};
    init_entity(&carti, 112, 64, carti_bounding_boxes, carti_metasprites, CARTI_TILE_OFFSET);
    uint8_t oam_index;
    // Boucle de jeu principale
    while(1) {
	// On attend la prochaine frame
        vsync();

	// Mise à jour des entrées
	UPDATE_KEYS();
	// Déplacement de l'entité carti en fonction des entrées
	uint16_t old_x = carti.x;
	uint16_t old_y = carti.y;
	
	if (KEY_PRESSED(J_LEFT)) {
	    carti.x = carti.x - (2<<6);
	}
	if (KEY_PRESSED(J_RIGHT)) {
	    carti.x = carti.x + (2<<6);
	}
	if (KEY_PRESSED(J_UP)) {
	    carti.y = carti.y - (2<<6);
	}
	if (KEY_PRESSED(J_DOWN)) {
	    carti.y = carti.y + (2<<6);
	}
	
	uint8_t collision = ENTITY_NO_COLLISION;
	// On vérifie la collision entre l'entité carti et chaque box
	for (uint8_t i=0; i<4; i++) {
	    collision |= check_collision(&carti, &box[i]);
	}
	// Si une collision est détectée, on annule le déplacement dans la direction correspondante
	
	if (collision & ENTITY_COLLISION_LEFT || collision & ENTITY_COLLISION_RIGHT) {
	    carti.x = old_x;
	}
	if (collision & ENTITY_COLLISION_UP || collision & ENTITY_COLLISION_DOWN) {
	    carti.y = old_y;
	}

	
	// On initialise l'index OAM	
	oam_index = 0;
	// On dessine l'entité
	for (uint8_t i=0; i<4; i++) {
	    oam_index += draw_entity(&box[i], oam_index);
	}
	oam_index = draw_entity(&carti, oam_index);

	// On vérifie la collision entre les deux entités
	
	
	
    }
}
