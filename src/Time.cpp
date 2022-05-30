#include "Time.h"
#include <unistd.h>
#include <stdio.h>
#include <arch/timer.h>
#include <arch/types.h>

/*limits for deltaTime*/
#define LOWDELTA 0.0167
#define HIGHDELTA 0.1f

/*worse code i have ever written*/
/*also fuck this shit i ain't using it */ 

static float timer;
float dt = 0;
uint64 lastFrame;  
uint64 begin, end;
const int FPS = 30; 
const int frameDelay = 1000 / FPS;

void Time::Init()
{
    timer_prime(TMU0, 1, 1);
    timer_start(TMU0);
}

void Time::Update()
{
    timer    += 0.0212f;
	uint64 c  = 1000/begin; 
	dt        = float(c - lastFrame);
	lastFrame = c;
}

float Time::time()
{
    return timer;
}

float Time::deltaTime()
{
    if (dt < LOWDELTA) {dt = LOWDELTA;}
	if(dt > HIGHDELTA) {dt = HIGHDELTA;}
    
    return dt;
}

void Time::StartFPStick()
{
	begin = timer_ms_gettime64();
}

void Time::EndFPStick()
{
	end = timer_ms_gettime64();
}

void Time::FPSlock()
{
	uint64 fps = end - begin;  
	if (frameDelay > fps)
	sleep((frameDelay-fps)/1000);
}