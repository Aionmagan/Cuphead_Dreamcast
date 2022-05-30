#ifndef __ANIMATOR__
#define __ANIMATOR__

#include "Sprite.h"

typedef struct
{
    int  length; 
    bool clamp;
}animLimit_t;

enum AnimState
{
    IDLE = 0,
    IDLEST,
    RUN,
    JUMP,
    DASH,
    DUCK,
};

class Animator
{
private:
    int          animSelect; 
    int          animMulSelect; 
    float        animationTime; 
    
    AnimState    animationState;
    Sprites     *spriteSheet = NULL;
    
    float       *animSpeeds  = NULL;
    animLimit_t *animLimit   = NULL;
    Vector      *animScales  = NULL;
    
    uv_t        *idleUV      = NULL;
    uv_t        *idleshotUV  = NULL;
    uv_t        *runUV       = NULL;
    uv_t        *jumpUV      = NULL;
    uv_t        *dashUV      = NULL;
    uv_t        *duckUV      = NULL;
    uv_t         temp[4]; 
    
public:
    Animator(Sprites *spriteSheet, float *speeds, animLimit_t *limits, Vector *scales, uv_t *idle, 
             uv_t *idleshot, uv_t *run, uv_t *jump, uv_t *dash, uv_t *duck);
    ~Animator();
    
    void      Update();
    int       GetAnimFrame();
    void      SetState(AnimState state, bool reset);
    AnimState GetState();
};

#endif //__PLAYERANIMATION__