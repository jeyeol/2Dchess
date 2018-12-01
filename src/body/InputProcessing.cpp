#include "pch.h"
#include "src/header/InputProcessing.h"
InputProcessing::InputProcessing()
{
	JustStarted = true;
	isSelected = false;
}


InputProcessing::~InputProcessing()
{

}

void InputProcessing::MouseInput(std::vector<Unit>&Unit_)
{
	if (isSelected&& !JustStarted) {
	Unit_.back().SetX(Board_.GridX(Board_.Xcood(Event.motion.x)));
	Unit_.back().SetY(Board_.GridY(Board_.Ycood(Event.motion.y)));
	}
		
	while (SDL_PollEvent(&Event))
	{
	
		switch (Event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			
				if (Event.button.button == SDL_BUTTON_LEFT && Board_.Xcood(Unit_.back().GetX())==Board_.Xcood(Event.motion.x)
				&& Board_.Ycood(Unit_.back().GetY()) == Board_.Ycood(Event.motion.y))
				{
					    JustStarted = false;
						isSelected = true;
					    std::cout << "position is right!";				

				}
				
				break;
		case SDL_MOUSEBUTTONUP:
			if (Event.button.button == SDL_BUTTON_LEFT)
			{
				JustStarted = false;
				isSelected = false;

				
				//std::cout << "selcted sprite is -->" << _ << std::endl;
				std::cout << "mouse is released at x ->   " << Unit_.back().GetX() << "   y ->" << Unit_.back().GetY();
				std::cout << "now the target x ->" << targetX << "  y->  " << targetY << std::endl;
			}break;
		/*case SDL_MOUSEMOTION:
			if (Event.button.button == SDL_BUTTON_LEFT && isSelected)
			{
				JustStarted = false;
				isSelected = true;
				targetX=Event.motion.x;
				targetY=Event.motion.y;
				std::cout << "sprite selected !" << std::endl;
				
			}
			*/
		default:
		{
			//Board_.Xcood(Unit_.back().GetX());
			//beforeY = Board_.Ycood(Unit_.back().GetY());
		}

		}
	}
}


