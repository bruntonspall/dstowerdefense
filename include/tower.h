typedef struct _tower {
  drawable_t drawable;
  int sprite_id;
  int target;
  int state;
} tower_t;

extern const u8 gfx_tower[16*16] __attribute__ ((aligned (4)));
extern const u16 pal_tower[8] __attribute__ ((aligned (4)));

