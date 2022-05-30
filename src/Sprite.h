#ifndef _SPRITE_
#define _SPRITE_

#include <plx/sprite.h>
#include <tsu/texture.h>
#include <tsu/drawables/banner.h>

typedef struct 
{
    float u;
    float v;
}uv_t; 

class Sprites
{
private: 
    RefPtr<Banner>  sprite; 
    RefPtr<Texture> sheet; 
    uv_t            uv[4]; 
    
public:
    Sprites(char *s);
    ~Sprites();
    
    void SetTranslate(Vector v); 
    void SetScale(Vector v); 
    void SetRotation(Vector v); //z axis and maybe
    
    void setUV(uv_t *uv);
    void flipSprite(bool flip);
    void Render();
};

#endif //_SPRITE_