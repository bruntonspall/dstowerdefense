// Includes
#include "dstowerdefense.h"

const u8 gfx_cursor[16*16] __attribute__ ((aligned (4))) = {
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,

0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
};
const u16 pal_cursor[8] __attribute__ ((aligned (4))) = { 0x0000, PA_RGB(31,31,31), PA_RGB(15,15,15), 0x0022 };

u8 grid[8*8] = {
    1, 1, 1, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 1, 0, 1, 0,
    0, 1, 1, 1, 1, 0, 1, 0,
    0, 0, 0, 0, 1, 0, 1, 0,
    0, 0, 0, 0, 1, 0, 1, 0,
    0, 0, 0, 0, 1, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 0, 0
};

const u8 SPRITE_TOWER_BASE = 32;
const u8 SPRITE_BASE = 0;

void setupRotations() {
    for (u16 r = 0; r < 511; r+= 64) {
      PA_SetRotsetNoZoom(0, r/64, r);
    }
}

typedef struct _tower_list {
    struct _tower_list * next;
    tower_t *tower;
} tower_list_t;

tower_list_t *tower_list_head = 0x00;
tower_list_t *tower_list_tail = 0x00;

void append_tower(tower_t* t) {
    tower_list_t *node;
    if (tower_list_tail == 0x00) {
        // Empty List
        node =malloc(sizeof(tower_list_t));
        tower_list_head = tower_list_tail = node;
    } else {

    }
}

// Function: main()
int main(int argc, char ** argv)
{
	PA_Init();    // Initializes PA_Lib
	PA_InitVBL(); // Initializes a standard VBL
  PA_InitText(1,1);
  drawable_t cursor;
  drawable_setup(&cursor, 0, 0, 0);
  drawable_load(&cursor, 0, 0, (void*)pal_cursor, (void*)gfx_cursor, OBJ_SIZE_16X16, 1);
  tower_t *towers = malloc(sizeof(tower_t)*8*8);
  tower_t *current_tower = towers;
  setupRotations();
  u8 i = 0;
  u8 x = 0;
  u8 y = 0;
  for (y = 0; y != 8; ++y) {
      for (x = 0; x != 8; ++x) {
          u16 i = y*8+x;
          if (grid[i] == 1) {
            drawable_setup(&current_tower->drawable, SPRITE_TOWER_BASE+i, x*16, y*16);
            drawable_load(&current_tower->drawable, 0, 1, (void*)pal_tower, (void*)gfx_tower, OBJ_SIZE_16X16, 1);
            //PA_SetSpriteRotEnable(0, current_tower->drawable.sprite, i);
            current_tower ++;
          }
      }
  }
  *current_tower = 0x00

  u16 angle = 0;

	// Infinite loop to keep the program running
	while (1)
	{
	    current_tower = towers;
    for (current_tower = towers; i != 10; ++i) {
      angle = drawable_get_angle_to(&towers[i].drawable, &cursor);
    }
    PA_OutputText(1, 0, 0, "Angle: %03d", angle);
    PA_OutputText(1, 0, 2, "Cursor: %03d,%03d", cursor.position.x, cursor.position.y);
		cursor.position.x += (Pad.Held.Right - Pad.Held.Left);
		cursor.position.y += (Pad.Held.Down - Pad.Held.Up);
    drawable_draw(&cursor);
		PA_WaitForVBL();
	}

	return 0;
} // End of main()
