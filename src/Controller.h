#ifndef _CONTROLLER_
#define _CONTROLLER_

#include <dc/maple.h>
#include <dc/maple/controller.h>

/*
 *the Button function in Controller class 
 * is used in this manner
 * controller.Button(START);
 */

enum Buttons
{
	PAD_A     = (1<<2),
	PAD_B     = (1<<1), 
	PAD_X     = (1<<10),
	PAD_Y     = (1<<9),
    PAD_UP    = (1<<4),
    PAD_DOWN  = (1<<5),
    PAD_LEFT  = (1<<6),
    PAD_RIGHT = (1<<7),
	PAD_START = (1<<3),
};

class Controller
{
private:
	cont_state_t *state;
	bool          release[4];
    int           ButtonUsed(Buttons button);
    
public:
	Controller();
	~Controller();
	
	void  UpdateControllerState();
	
	bool  ButtonHold(Buttons button) const;
	bool  ButtonDown(Buttons button);
	bool  ButtonUp(Buttons button);
    
	float JoystickX() const;
	float JoystickY() const;
    float RightTrigger() const;
    float LeftTrigger() const;
};

#endif //_CONTROLLER_