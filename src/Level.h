#ifndef __LEVEL__
#define __LEVEL__

#include <tsu/drawable.h>
#include "Sprite.h"

class Level
{
private:
    
    
public:
    Level(float x, float y, float size);
    ~Level();
    
    void Render();
};

#endif //__LEVEL__