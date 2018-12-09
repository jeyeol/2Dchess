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
			
			{
				if (Event.button.button != SDL_BUTTON_LEFT) break;
				for (auto& piece : Unit_)
				if (Board_.Xcood(Event.motion.x) == Board_.Xcood(piece.GetX())
					&& Board_.Ycood(Event.motion.y) == Board_.Ycood(piece.GetY()))
				{
					Selected = &piece;
					//assign old position for piece
					beforeX = Selected->GetX();
					beforeY = Selected->GetY();
					//intergrate into unit class
					Selected->oldX = beforeX;
					Selected->oldY = beforeY;
					if (Selected->WHITE) { CurrentPlayer = 'W'; };
					if (Selected->BLACK) { CurrentPlayer = 'B'; };
					break;
				}
				
			}
			
			break;
		case SDL_MOUSEBUTTONUP:
			if (Event.button.button == SDL_BUTTON_LEFT)
			{
				Selected = nullptr;	
				if (targetX != beforeX or targetY != beforeY)
				{
					if (CurrentPlayer == 'W') { WhiteTurn = false; }; break;
					if (CurrentPlayer == 'B') { WhiteTurn = true; }; break;
				}
				break;
			
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
	
	if (Selected != nullptr)
	{
		//set new target positions for the piece
		Selected->SetX(Board_.GridX(Board_.Xcood(Event.motion.x)));
		Selected->SetY(Board_.GridY(Board_.Ycood(Event.motion.y)));
		//change in position
		dx = Selected->GetX() - beforeX;
		dy = Selected->GetY() - beforeY;	
		//new position
		targetX = beforeX + dx;
		targetY = beforeY + dy;
		Selected->newX = targetX;
		Selected->newY = targetY;
		
		
	}

	
	
}
		

	



