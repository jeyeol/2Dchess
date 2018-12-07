#include "pch.h"
#include "src/header/InputProcessing.h"
InputProcessing::InputProcessing()
{
	
}


InputProcessing::~InputProcessing()
{

}

void InputProcessing::MouseInput(std::vector<Unit>& Unit_)
{
	
			
		while (SDL_PollEvent(&Event))
		{

			switch (Event.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				if (Event.button.button != SDL_BUTTON_LEFT) break;
				for (auto& piece : Unit_)
				if (Board_.Xcood(Event.motion.x)== Board_.Xcood(piece.GetX())
					&& Board_.Ycood(Event.motion.y)== Board_.Ycood(piece.GetY()))
				{
					Selected = &piece;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (Event.button.button == SDL_BUTTON_LEFT)
				{
					Selected = nullptr;
					
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
				 
			}

			}
		}
		if (Selected !=nullptr)
		{
			Selected->SetX(Board_.GridX(Board_.Xcood(Event.motion.x)));
			Selected->SetY(Board_.GridY(Board_.Ycood(Event.motion.y)));
			Turnchange = true;
		}
}

	



