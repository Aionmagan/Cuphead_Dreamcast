#include <stdlib.h>

#include "Enemy.h"
#include "EnemyAnimation.h"
#include "Controller.h"

extern Controller controller; 

Enemy::Enemy(float x, float y, float speed):Drawable()
{
	moveSpeed = speed; 
	direction = -1;
	sprite    = new Sprites("rd/Sprite/Enemy/GoopeSheet.png");
	animation = new Animator(sprite, animationSpeeds, animationLength, animationScales,
							 idleUV, idleShotUV, runUV, NULL, NULL, NULL);
	animation->SetState(RUN, true);

	sprite->flipSprite(false);
	setTranslate(Vector(x, y, 18));
	sprite->SetTranslate(getPosition());
}

Enemy::~Enemy()
{
	
}

void Enemy::Update()
{	
	if (onGround)
	{
		if (animation->GetAnimFrame() >= animationLength[0].length-1)
		{
			animation->SetState(RUN, true);
			
			int rnd    = rand() % 20;
			float jump = rnd + 45;
			float left = rnd + 15;
			velocity   = Vector(left * direction, -jump, 0);
		}else 
		{
			animation->SetState(IDLE, true);
		}
	}else
	{
		if(velocity[1] > 3.3f)
		{
			animation->SetState(IDLEST, true);
		}
	}
	
	translate(velocity * 0.333333f);
	velocity = velocity + gravity * 0.333333f;
	curPos   = getPosition();
	
	if (curPos[0] < 30)
    {
        curPos    = Vector(31, curPos[1], 18);
		direction = 1;
		velocity  = Vector(velocity[0] * -direction, velocity[1], 0);
    }
	else if (curPos[0] > 610)
    {
        curPos    = Vector(609, curPos[1], 18);
		direction = -1;
		velocity  = Vector(velocity[0] * direction, velocity[1], 0);
    }
	
	if (curPos[1] > 346)
    {
        curPos   = Vector(curPos[0], 345, 18); 
        onGround = true;
        canJump  = true; 
		velocity.zero();
    }else 
    {
        onGround = false;
    }
	
	setTranslate(curPos);
	sprite->SetTranslate(getPosition());
	
	animation->Update();
}

void Enemy::Render()
{
	sprite->flipSprite(direction > 0);
	sprite->Render();
}