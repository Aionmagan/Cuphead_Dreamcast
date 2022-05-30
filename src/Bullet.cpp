#include "Bullet.h"
#include "Sprite.h"

static Sprites *sprite = NULL; //all bullets will use this
	
Bullet::Bullet(float x, float y, float size, float speed) : Drawable()
{
	direction  = 1; 
	moveSpeed  = speed;
	isShot     = false;
	this->size = size;
	
	
	setTranslate(Vector(x, y, 19));
	
	if (sprite == NULL)
	{
		sprite = new Sprites("rd/Sprite/shot.png"); 
		sprite->SetScale(Vector(size, size, 1));
	}
}

Bullet::~Bullet()
{
	
}

void Bullet::Update()
{
	curPos = getPosition();
	
	if (!isShot)
	{
		setTranslate(Vector(-1.5f, -1.5f, 21));
		return;
	}
	
	if (curPos[0] < 30 || curPos[0] > 610){ isShot = false;}
	dir = Vector(direction * moveSpeed, 0, 0);
	translate(dir * 0.333333f);
}

void Bullet::Render()
{
	if (!isShot){return;}
	
	sprite->SetTranslate(curPos);
	
	sprite->flipSprite(direction < 0);
	sprite->Render();
}

void Bullet::Shoot(Drawable &object)
{
	x = object.getPosition()[0];
	y = object.getPosition()[1];
	setTranslate(Vector(x, y, 17));
	isShot = true; 
}

void Bullet::SetDirection(int direction)
{
    if (direction == 0){return;}
    this->direction = direction;
}

bool Bullet::GetActive()
{
	return isShot; 
}

bool Bullet::AABB(Drawable &object)
{
	float xx = object.getPosition()[0];
	float yy = object.getPosition()[1];
	
	if (curPos[0] < xx + 75       &&
		curPos[0] + size > xx     && 
		curPos[1] < yy + 75       &&
		curPos[1] + size * 0.5f > yy)
		{	
	        isShot = false;
			return true;
		}
		 
	return false;
}