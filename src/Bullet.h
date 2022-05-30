#ifndef _BULLET_
#define _BULLET_

#include <tsu/drawable.h>
#include <tsu/vector.h>


//#include "Player.h"

class Bullet : Drawable
{
private: 
	float  moveSpeed;
	float  size;
	int    direction; 
	bool   isShot;
	float  x, y;
	Vector curPos;
	Vector dir; 
	
public: 
	Bullet(float x, float y, float size,float speed);
	~Bullet(); 

	void Update();
	void Render();
	void Shoot(Drawable &object);
	void SetDirection(int direction);
    bool AABB(Drawable &object);
	bool GetActive();
};

#endif /*_BULLET_*/