#include "Controller.h"
#include <stdio.h>

Controller::Controller()
{
	UpdateControllerState();
    
    for(int i = 0; i < 4; ++i)
    {
        release[i] = false;
    }
}

Controller::~Controller()
{
	
}

int Controller::ButtonUsed(Buttons button)
{
    switch(button)
    {
        case PAD_A:
            return 0; 
            break;
        case PAD_B:
            return 1;
            break;
        case PAD_X: 
            return 2;
            break;
        case PAD_Y:
            return 3;
            break;
        default:
            break;
    }
    
    return -1;
}

void Controller::UpdateControllerState()
{
	state = (cont_state_t *)maple_dev_status(maple_enum_type(0, MAPLE_FUNC_CONTROLLER));
}

bool Controller::ButtonHold(Buttons button) const
{
	if(state != NULL)
	{
		return state->buttons & button;
	}
	return false;
}

bool Controller::ButtonDown(Buttons button) 
{
    if(state != NULL)
    {        
        int bu = ButtonUsed(button);
        if((state->buttons & button))
        {
            if (!release[bu])
            {
                release[bu] = true;
                return true;
            }
        }
    }
    return false;
}

bool Controller::ButtonUp(Buttons button) 
{
    if(state != NULL)
    {
        int bu = ButtonUsed(button);
        if(!(state->buttons & button))
        {
            if (release[bu])
            {
                release[bu] = false;
                return true;
            }
        }
    }
    return false;
}

float Controller::JoystickX() const
{
	if(state != NULL)
	{
		return state->joyx / 126;
	}
	
	return 0;
}

float Controller::JoystickY() const
{
	if(state != NULL)
	{
		return state->joyy / 126;
	}
	
	return 0;
}

float Controller::RightTrigger() const
{
    if(state != NULL)
    {
        return state->rtrig;
    }
    
    return 0;
}

float Controller::LeftTrigger() const
{
    if(state != NULL)
    {
        return state->ltrig;
    }
    
    return 0;
}
