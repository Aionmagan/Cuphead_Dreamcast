#include "Level.h"
#include "Sprite.h"

#define XOFFSET 0.5

static RefPtr<Banner>  backGround; 
static RefPtr<Banner>  foreGround;

static RefPtr<Texture> lvlbg;
static RefPtr<Texture> lvlfg;

Level::Level(float x, float y, float size)
{
    lvlbg      = new Texture("/rd/Sprite/Level/bg.png", true);
    lvlfg      = new Texture("/rd/Sprite/Level/fg.png", true);
    
    backGround = new Banner(PVR_LIST_TR_POLY, lvlbg);
    foreGround = new Banner(PVR_LIST_TR_POLY, lvlfg);
    
    backGround->setScale(Vector(size + XOFFSET, size, 1));
    foreGround->setScale(Vector(size + XOFFSET, size, 1));
    
    backGround->setTranslate(Vector(x, y, 1));
    foreGround->setTranslate(Vector(x, y, 50));
}

Level::~Level()
{
    delete backGround;
	delete foreGround;
	delete lvlbg;
	delete lvlfg;
}

void Level::Render()
{
    backGround->draw(PVR_LIST_TR_POLY);
    foreGround->draw(PVR_LIST_TR_POLY);
}

