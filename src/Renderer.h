#ifndef __RENDERER__
#define __RENDERER__

class Render
{
public:
    static void Init();
    static void ShutDown();
    static void TransparentBegin(); 
    static void OpequeBegin();
    static void Finish();
};

#endif //__RENDERER__