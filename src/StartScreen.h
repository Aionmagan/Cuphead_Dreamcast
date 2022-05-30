#ifndef __STARTSCREEN__

#include "Renderer.h"
#include "Sprite.h"

void IntroScreen()
{
    Sprites *sprite = new Sprites("/rd/Sprite/StartScreen.png");
        
    //move icon around
    sprite->SetTranslate(Vector(640/2, 480/2, 20));
    sprite->SetScale(Vector(1.3f, 1.01f, 1));
        
    Render::TransparentBegin();
    sprite->Render();
    Render::Finish();
}

#endif //__STARTSCREEN__