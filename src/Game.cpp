#include "Game.h"

#include "Controller.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Time.h"
#include "Level.h"

#include <stdlib.h>
#include <time.h>

#define BULLETAMOUNT 20

extern Controller controller; 
Player           *player      = NULL;
Enemy            *enemy       = NULL;
Level            *level       = NULL;
Bullet           *bullet[BULLETAMOUNT];

bool              gameRunning = false;

void Game::Start()
{
    gameRunning = true;
    
    level       = new Level(640/2, 480/2, 1);
	player      = new Player(100, 366, 24.5f);
	enemy       = new Enemy(600, 366, 24.5f);
	
	for(int i = 0; i < BULLETAMOUNT; ++i)
	{
		bullet[i] = new Bullet(0, 0, 2, 35.7f);
	}
}

void Game::End()
{	
	delete player;
	delete enemy; 
	delete bullet[BULLETAMOUNT];
}

float shotspeed = 0.2f;
float startTime = 0; 
void Game::Update()
{
	if (controller.ButtonHold(PAD_START)){gameRunning = false;}
	
	if (controller.ButtonHold(PAD_X))
	{
        if (startTime < Time::time())
        {
		for(int i = 0; i < BULLETAMOUNT; ++i)
		{
			if (!bullet[i]->GetActive())
			{
                bullet[i]->SetDirection(player->GetDirection());
				bullet[i]->Shoot(*player);
				goto out;
			}
		}
        
		
		out:
        
        startTime = Time::time() + shotspeed;
        }
	}
    
	enemy->Update();
	player->Update();
	for(int i = 0; i < BULLETAMOUNT; ++i)
	{
		bullet[i]->Update();
	}
	
}

void Game::Render()
{
    level->Render();
	player->Render();
	enemy->Render();
	for(int i = 0; i < BULLETAMOUNT; ++i)
	{
		if (bullet[i]->GetActive())
		{
			if (!bullet[i]->AABB(*enemy))
			{
				bullet[i]->Render();
			}
		}
	}
}

bool Game::Running()
{
	return gameRunning;
}