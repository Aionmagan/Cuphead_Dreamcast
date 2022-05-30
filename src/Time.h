#ifndef __TIME_H__
#define __TIME_H__

class Time
{
public:
    static void Init();
    static void Update();
    static float time();
    static float deltaTime();
    static void StartFPStick();
    static void EndFPStick();
    static void FPSlock();
};

#endif //__TIME_H__