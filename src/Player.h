#ifndef _PLAYER_
#define _PLAYER_

//#include <tsu/include/texture.h>

//#include "GameObject.h"
#include "Animator.h"
#include "Sprite.h"
#include <tsu/drawable.h>
#include <tsu/vector.h>

class Player : public Drawable
{
private :
	float     moveSpeed;
	int       direction; 
	
	Animator *animation  = NULL;
	Sprites  *sprite     = NULL; 
    
	bool      canJump    = true;
    bool      onGround   = true;
	
	bool      dash       = false; 
    float     dashTimer  = 0; 
    float     dashAmount = 0.3f;

	Vector    gravity    = Vector(0, 9.87f, 0, 1);
	Vector    velocity; 
    Vector    curPos; 
public :
	Player(float x, float y, float speed);//:GameObject(x, y, size);
	~Player();
	
	void Update();
	void Render();
	int GetDirection();	
};

#endif //_PLAYER_