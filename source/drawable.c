#include "dstowerdefense.h"

void drawable_setup(drawable_t *drawable, u8 sprite_id, u8 x, u8 y) {
  drawable->sprite = sprite_id;
  drawable->position.x = x;
  drawable->position.y = y;
}

void drawable_load(drawable_t *drawable, u8 screen, u8 palette_num, void * palette_data, void *gfx_data, u8 shape, u8 size, u8 colour_mode) {
	PA_LoadSpritePal(screen, palette_num, palette_data);
	PA_CreateSprite(screen, drawable->sprite, gfx_data, shape, size, colour_mode, palette_num, drawable->position.x, drawable->position.y);
}

void drawable_draw(drawable_t *drawable) {
  PA_SetSpriteXY(0, drawable->sprite, drawable->position.x, drawable->position.y);
}

u16 drawable_get_angle_to(drawable_t*self, drawable_t* other) {
    return PA_GetAngle(self->position.x, self->position.y, other->position.x, other->position.y);
}
