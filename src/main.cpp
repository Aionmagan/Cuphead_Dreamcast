#include <stdio.h>

#include "Game.h"
#include "Sprite.h"
#include "Renderer.h"
#include "Time.h"
#include "Controller.h"
#include "StartScreen.h"

extern uint8 romdisk[];
KOS_INIT_FLAGS(INIT_DEFAULT);
KOS_INIT_ROMDISK(romdisk);

Controller controller;

int main(int argc, char **argv)
{
    Time::Init();
    Render::Init();

    IntroScreen();

	Game::Start();
    
	while (Game::Running())
	{
        Time  ::StartFPStick();
        
        Time  ::Update();
        controller.UpdateControllerState();
		Game  ::Update();
        
        Render::TransparentBegin();
		Game  ::Render();
        Render::Finish();
        
        Time  ::deltaTime();        
        Time  ::EndFPStick();
		Time  ::FPSlock();
	}
    
    Game::End();
    Render::ShutDown();
}