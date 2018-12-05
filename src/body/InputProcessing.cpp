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

void InputProcessing::MouseInput(std::vector<Unit>& Unit_, int piece)
{
	
		if (isSelected && !JustStarted)
		{
			Unit_[piece].SetX(Board_.GridX(Board_.Xcood(Event.motion.x)));
			Unit_[piece].SetY(Board_.GridY(Board_.Ycood(Event.motion.y)));

		}
		
		std::cout << Board_.Xcood(Event.motion.x) << Board_.Ycood(Event.motion.y) <<std::endl;
		
		while (SDL_PollEvent(&Event))
		{

			switch (Event.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				
				if (Event.button.button == SDL_BUTTON_LEFT && Board_.Xcood(Event.motion.x)== Board_.Xcood(Unit_[piece].GetX())
					&& Board_.Ycood(Board_.Ycood(Event.motion.y))== Unit_[piece].GetY())
				{
						JustStarted = false;
						isSelected = true;
						std::cout << "position is right!";
						break;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (Event.button.button == SDL_BUTTON_LEFT)
				{
					JustStarted = false;
					isSelected = false;
					std::cout << "Button Up" << std::endl;
				}
				break;
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

	



