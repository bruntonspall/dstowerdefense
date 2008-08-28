/*
 * DS Tower Defense by MiBGames
 *
 * Main header file, ihcluding game definitions
 */
#include <PA9.h>       // Include for PA_Lib

typedef struct _pos {
  u8 x, y;
} pos_t;

typedef struct {
  pos_t position;
  u8 sprite;
} drawable_t;

extern void drawable_draw(drawable_t *drawable);
extern void drawable_setup(drawable_t *drawable, u8 sprite_id, u8 x, u8 y);
extern void drawable_load(drawable_t *drawable, u8 screen, u8 palette_num, void * palette_data, void *gfx_data, u8 shape, u8 size, u8 colour_mode);
extern u16 drawable_get_angle_to(drawable_t*self, drawable_t* other);

/* Include all necessary files for the game */
#include "tower.h"
