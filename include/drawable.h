#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED

class Position {
    public:
    u8 x, y;
    Position(u8 x, u8 y) : x(x), y(y) {}
};

class Drawable {
    public:
    Position position;
    u8 sprite;

    Drawable(u8 sprite, u8 x, u8 y) : sprite(sprite), position(x,y) {}
    void Draw();
    void Load(u8 screen, u8 palette_num, void * palette_data, void *gfx_data, u8 shape, u8 size, u8 colour_mode);
    u16 GetAngleTo(Drawable& other);
};


#endif // DRAWABLE_H_INCLUDED
