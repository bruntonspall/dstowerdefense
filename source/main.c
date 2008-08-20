// Includes
#include <PA9.h>       // Include for PA_Lib

#include "dstowerdefense.h"
#include "gfx_cursor.h"

pos_t cursor_pos;

typedef struct _drawable {
  pos_t position;
  u8 sprite;
} drawable;

drawable cursor;

// Function: main()
int main(int argc, char ** argv)
{
	PA_Init();    // Initializes PA_Lib
	PA_InitVBL(); // Initializes a standard VBL
  cursor.position.x = 0;
  cursor.position.y = 0;
  cursor.position.w = 8;
  cursor.position.h = 8;
  cursor.sprite = 0;
  PA_CreateSprite(0, cursor.sprite, (void *)gfx_cursor, OBJ_SIZE_8X8, 1, 0, cursor.position.x, cursor.position.y);

	// Infinite loop to keep the program running
	while (1)
	{
    cursor.position.x += (Pad.Held.Right - Pad.Held.Left);
    cursor.position.y += (Pad.Held.Up - Pad.Held.Down);
    PA_SetSpriteXY(0, cursor.sprite, cursor.position.x, cursor.position.y);
		PA_WaitForVBL();
	}
	
	return 0;
} // End of main()
