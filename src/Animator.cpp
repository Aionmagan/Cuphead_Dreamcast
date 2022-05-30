#include "Animator.h"
#include "Time.h"
#include <stdio.h>

Animator::Animator(Sprites *spriteSheet, float *speeds, animLimit_t *limits, Vector *scales,
                    uv_t *idle, uv_t *idleshot, uv_t *run, uv_t *jump, uv_t *dash, uv_t *duck)
{
    this->spriteSheet = spriteSheet;
    animSpeeds        = speeds;
    animLimit         = limits;
    animScales        = scales;
    idleUV            = idle;
    idleshotUV        = idleshot;
    runUV             = run; 
    jumpUV            = jump;
    dashUV            = dash; 
    duckUV            = duck;
    
    animationTime     = 0; 
    animSelect        = 0;
}

Animator::~Animator()
{
    delete spriteSheet;
    
    delete animSpeeds;
    delete animLimit;
    delete animScales;
    
    delete idleUV;
    delete idleshotUV;
    delete runUV;
    delete jumpUV;
    delete dashUV;
    delete duckUV;
}

void Animator::Update()
{
    animMulSelect = animSelect * 4;
    
    switch(animationState)
    {
        case IDLE:
            temp[0] = idleUV[0+animMulSelect];
            temp[1] = idleUV[1+animMulSelect];
            temp[2] = idleUV[2+animMulSelect];
            temp[3] = idleUV[3+animMulSelect];
            break;
        case IDLEST:
            temp[0] = idleshotUV[0+animMulSelect];
            temp[1] = idleshotUV[1+animMulSelect];
            temp[2] = idleshotUV[2+animMulSelect];
            temp[3] = idleshotUV[3+animMulSelect];
            break;
        case RUN:
            temp[0] = runUV[0+animMulSelect];
            temp[1] = runUV[1+animMulSelect];
            temp[2] = runUV[2+animMulSelect];
            temp[3] = runUV[3+animMulSelect];
            break;
        case DUCK:
            temp[0] = duckUV[0+animMulSelect];
            temp[1] = duckUV[1+animMulSelect];
            temp[2] = duckUV[2+animMulSelect];
            temp[3] = duckUV[3+animMulSelect];
            break;
        case JUMP:
            temp[0] = jumpUV[0+animMulSelect];
            temp[1] = jumpUV[1+animMulSelect];
            temp[2] = jumpUV[2+animMulSelect];
            temp[3] = jumpUV[3+animMulSelect];
            break;
        case DASH:
            temp[0] = dashUV[0+animMulSelect];
            temp[1] = dashUV[1+animMulSelect];
            temp[2] = dashUV[2+animMulSelect];
            temp[3] = dashUV[3+animMulSelect];
        default:
            break;
    }
    
    spriteSheet->setUV(temp);
    
    if (animationTime < Time::time())
    {
        animSelect++;
        animationTime = Time::time() + animSpeeds[animationState];
    }
    
    if(animSelect >= animLimit[animationState].length)
    {
        if(animLimit[animationState].clamp)
        {
            animSelect = animLimit[animationState].length-1;
        }
        else
        {
            animSelect = 0;
        }
    }
}

void Animator::SetState(AnimState animState, bool reset)
{
    if (animationState == animState){return;}
    
    if (reset)
    {
        animSelect = 0;
    }
    
    animationState = animState;
    spriteSheet->SetScale(animScales[animationState]);
}

int Animator::GetAnimFrame()
{
	return animSelect; 
}

AnimState Animator::GetState()
{
    return animationState;
}