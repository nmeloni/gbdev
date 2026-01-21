#include "body.h"

inline void init_body(body_t* body, uint8_t x, uint8_t y) {
	body->x = x;
	body->y = y;
	body->dx = 0;
	body->dy = 0;
	body->fx = 0;
	body->fy = 0;
}

inline void update_body_position(body_t* body) {
	// Mise à jour des parties fractionnaires
	body->fx += body->dx;
	body->fy += body->dy;

	// Mise à jour des positions entières
	body->x += body->fx >> 4; // Diviser par 16 pour obtenir la partie entière
	body->y += body->fy >> 4;

	// Conserver uniquement la partie fractionnaire
	body->fx &= 0x0F;
	body->fy &= 0x0F;
}

inline uint8_t clamp(uint8_t value, uint8_t min, uint8_t max) {
    // Clamp arithmétique pour uint8_t sans conditionnelles
    value = value  + ((min - value) & ((value-min) >> 7));
    value = value  - ((value - max) & ((max-value) >> 7));
    return value;
}
