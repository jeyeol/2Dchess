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
    bool GoodMove_();

		switch (Event.type)
		{
            if (Event.motion.x >= 480) {
                    Event.motion.x = 480;
                  }
            if (Event.motion.x < 28) {
                    Event.motion.x = 28;
                  }
			if (Event.motion.y < 28)
			{
                    Event.motion.y = 28;
			}
                        if (Event.motion.y >= 480) {
                          Event.motion.y = 480;
						}
             
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
					
					if (Selected->Color_ == Unit::WHITE) { CurrentPlayer = 'W'; std::cout << "white units selected"; };
					if (Selected->Color_ == Unit::BLACK) { CurrentPlayer = 'B'; std::cout << "black units selected"; };
                                        
				}
				
			}
			
			break;
		case SDL_MOUSEBUTTONUP:
			if (Event.button.button == SDL_BUTTON_LEFT)
			{
				Selected = nullptr;	
				if (targetX != beforeX or targetY != beforeY)
				{
					if (CurrentPlayer == 'W' && WhiteTurn) {WhiteTurn = false;};
					if (CurrentPlayer == 'B' && !WhiteTurn) {	WhiteTurn = true;};
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
	
	if (Selected != nullptr )
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
		

	



