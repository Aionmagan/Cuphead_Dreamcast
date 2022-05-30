#include "Sprite.h"
	
Sprites::Sprites(char *s)
{
    printf("pvr vram: %d\n",pvr_mem_available()/1024);
    sheet   = new Texture(s, true);
    sprite  = new Banner(PVR_LIST_TR_POLY, sheet);
    printf("pvr vram: %d\n",pvr_mem_available()/1024);
    
    uv[0].u = 0; uv[0].v = 1;
    uv[1].u = 0; uv[1].v = 0;
    uv[2].u = 1; uv[2].v = 1;
    uv[3].u = 1; uv[3].v = 0;
    
}

Sprites::~Sprites()
{
	delete sheet;
    delete sprite; 
}

void Sprites::SetTranslate(Vector v)
{
    sprite->setTranslate(v);
}

void Sprites::SetScale(Vector v)
{
    sprite->setScale(v);
}

void Sprites::SetRotation(Vector v) //only obeys Z axis 
{
    sprite->setRotate(v);
}

void Sprites::setUV(uv_t *uv)
{
    this->uv[0] = uv[0]; 
    this->uv[1] = uv[1]; 
    this->uv[2] = uv[2]; 
    this->uv[3] = uv[3]; 
}

void Sprites::flipSprite(bool flip)
{
    if (flip)
    {
        sprite->setUV(uv[2].u, uv[2].v,
                      uv[3].u, uv[3].v,
                      uv[0].u, uv[0].v,
                      uv[1].u, uv[1].v);
    }else{
        sprite->setUV(uv[0].u, uv[0].v,
                      uv[1].u, uv[1].v,
                      uv[2].u, uv[2].v,
                      uv[3].u, uv[3].v);        
    }   
}

void Sprites::Render()
{
    sprite->draw(PVR_LIST_TR_POLY);
}
