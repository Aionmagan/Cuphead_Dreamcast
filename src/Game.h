#ifndef _GAME_
#define _GAME_

class Game 
{
public:
	static void Start(); // call this only once
	static void Update(); // maybe will add dt later
	static void Render();
	static void End();
	static bool Running();
	
};

#endif //_GAME_