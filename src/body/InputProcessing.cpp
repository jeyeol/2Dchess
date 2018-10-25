#include "pch.h"
#include "src/header/InputProcessing.h"
InputProcessing::InputProcessing()
{
	
	
}


InputProcessing::~InputProcessing()
{

}

void InputProcessing::MouseInput(std::vector<Unit>Unit_)
{
	while (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			
				if (Event.button.button == SDL_BUTTON_LEFT)
				{
					if(Board_.Xcood(Event.motion.x) == Board_.Xcood(Unit_.back().GetX())
						&& Board_.Ycood(Event.motion.y) == Board_.Ycood(Unit_.back().GetY()))
					{
						isSelected = true;
						std::cout << "position is right!";
					}
					else { isSelected = false; };
				}
				break;
		case SDL_MOUSEBUTTONUP:
			
				isSelected = false;
				if (Event.button.button == SDL_BUTTON_LEFT && !isSelected)
				{
					Unit_.back().TargetX_=Unit_.back().SetX(Board_.GridX(Board_.Xcood(Event.motion.x)));
					Unit_.back().TargetY_ =Unit_.back().SetY(Board_.GridY(Board_.Ycood(Event.motion.y)));
					std::cout << "mouse is released at x ->   " << Unit_.back().GetX() << "   y ->" << Unit_.back().GetY();
				}
				break;
		case SDL_MOUSEMOTION:
			if (Event.button.button == SDL_BUTTON_LEFT && isSelected)
			{
				Unit_.back().TargetX_ = Event.motion.x;
				Unit_.back().TargetY_ = Event.motion.y;
				Unit_.back().SetX(Unit_.back().TargetX_);
				Unit_.back().SetY(Unit_.back().TargetY_);
				std::cout << "sprite selected !" << std::endl;
			}
		default:
		{
			Unit_.back().TargetX_ = Unit_.back().GetX();
			Unit_.back().TargetY_ = Unit_.back().GetY();
			std::cout << "default position is at :  x->  " << Unit_.back().GetX() << " y->  " << Unit_.back().GetY() << std::endl;
		}

		}
	}
}


