#include "Player.h"
#include "Controller.h" //for controller
#include "Time.h"
#include "PlayerAnimation.h"

extern Controller controller;

Player::Player(float x, float y, float speed):Drawable()
{
	moveSpeed = speed;
	direction = 1;
    sprite    = new Sprites("/rd/Sprite/Player/playerSheet.png");
    animation = new Animator(sprite, animationSpeeds, animationLength, animationScales, 
                             idleUV, idleShotUV, runUV, jumpUV, dashUV, duckUV);
    animation->SetState(IDLE, true);
    
    sprite->flipSprite(false);
    setTranslate(Vector(x, y, 20));
    sprite->SetTranslate(getPosition());
}

Player::~Player()
{
	
}

void Player::Update()
{
    if (dash)
	{
		if (dashTimer < Time::time())
		{
			dash = false;
			animation->SetState(JUMP, true);
		}else
		{
			velocity = Vector(direction * 35, 0, 0);
		}
		
		goto skip; //skip a few logics 
	}
	
    if (onGround)
    {
		if (controller.JoystickY() > 0.7f)
		{
			animation->SetState(DUCK, true);
			animation->Update();
			return;
		}
		
        if (controller.JoystickX() > 0.5f || controller.JoystickX() < -0.5f)
        {
            animation->SetState(RUN, true);
        }else 
        {
			if (controller.ButtonHold(PAD_X))
			{
				animation->SetState(IDLEST, true);
			}
			else
			{
				animation->SetState(IDLE, true);
			}
        }
    } 
	
    if (controller.ButtonDown(PAD_A))
    {
        if (canJump)
        {
            velocity = Vector(velocity[0], -50.0f, 20);
            animation->SetState(JUMP, false);
            canJump  = false; 
        }
        
    }

    if (controller.ButtonUp(PAD_A))
    {
        velocity.zero();
    }
	
	if (controller.ButtonDown(PAD_Y) && !dash)
	{
		animation->SetState(DASH, true);
		dash      = true;
		dashTimer = Time::time() + dashAmount;
	}
	skip:
	//update the button press
	controller.ButtonUp(PAD_Y);

    translate(velocity * 0.333333f);
    
    velocity = Vector(controller.JoystickX() * moveSpeed, velocity[1], 0);
    velocity = velocity + gravity * 0.333333f;
    curPos   = getPosition();
 
	if (curPos[0] < 30)
    {
        curPos = Vector(31, curPos[1], 20);
    }
	else if (curPos[0] > 610)
    {
        curPos = Vector(609, curPos[1], 20);
    }
	
	if (curPos[1] < 30)
    {
        curPos = Vector(curPos[0], 31, 20);
    }
	else if (curPos[1] > 366)
    {
        curPos   = Vector(curPos[0], 365, 20); 
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

void Player::Render()
{	
    if (!dash)
	{
		if (controller.JoystickX() < -0.5f)
		{
			direction = -1;

		}else if (controller.JoystickX() > 0.5f)
		{
			direction = 1;
		}
	}
    
    sprite->flipSprite(direction < 0);
    sprite->Render();
}

int Player::GetDirection()
{
    return direction;
}