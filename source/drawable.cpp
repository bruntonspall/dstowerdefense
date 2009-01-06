#include "dstowerdefense.h"

void Drawable::Draw()
{
    PA_SetSpriteXY(0, this->sprite, this->position.x, this->position.y);
}

void Drawable::Load(u8 screen, u8 palette_num, void * palette_data, void *gfx_data, u8 shape, u8 size, u8 colour_mode)
{
    PA_LoadSpritePal(screen, palette_num, palette_data);
    PA_CreateSprite(screen, this->sprite, gfx_data, shape, size, colour_mode, palette_num, this->position.x, this->position.y);
}

u16 Drawable::GetAngleTo(Drawable& other)
{
    return PA_GetAngle(this->position.x, this->position.y, other.position.x, other.position.y);
}
