#include "src/header/InputProcessing.h"
#include "pch.h"

InputProcessing::InputProcessing()
{
	xbefore_ = Unit_.GetX();
	ybefore_ = Unit_.GetY();
	
}


InputProcessing::~InputProcessing()
{

}

void InputProcessing::MouseInput()
{
	while (SDL_PollEvent(&Event))
	{
		switch (Event.button.button) 
		{
		case SDL_MOUSEBUTTONDOWN:
			xTarget_ = Event.motion.x;
			yTarget_ = Event.motion.y;
		case SDL_MOUSEBUTTONUP:
			;
		}
	}
}