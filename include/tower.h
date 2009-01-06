class Tower : public Drawable {
    public:
    int sprite_id;
    int target;
    int state;
    Tower(u8 sprite, u8 x, u8 y) : Drawable(sprite, x, y) {};
};

extern const u8 gfx_tower[16*16] __attribute__ ((aligned (4)));
extern const u16 pal_tower[8] __attribute__ ((aligned (4)));

