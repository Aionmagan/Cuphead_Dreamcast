#ifndef __ENEMY__
#define __ENEMY__

#include <tsu/drawable.h>
#include <tsu/vector.h>

#include "Sprite.h"
#include "Animator.h"

/*this could have been virtualized... i'm an idiot
 * now i have two exact class player and enemy*/

class Enemy : public Drawable
{
private : 
	float     moveSpeed; 
	int       direction; 
	
	Animator *animation = NULL;
	Sprites  *sprite    = NULL; 
	
	bool      canJump;
	bool      onGround; 
	
	Vector    velocity;
	Vector    curPos; 
	Vector    gravity   = Vector(0, 9.87f, 0, 1);
	
public :
	Enemy(float x, float y, float speed);
	~Enemy();
	
	void Update();
	void Render(); 
};

#endif /*__ENEMY */