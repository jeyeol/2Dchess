#include "pch.h"
#include "src/header/InputProcessing.h"


InputProcessing::InputProcessing() {}

InputProcessing::~InputProcessing() {}

void InputProcessing::MouseInput(std::vector<Unit>& Unit_) {
  while (SDL_PollEvent(&Event)) {
    switch (Event.type) {
      case SDL_MOUSEBUTTONDOWN:

      {
        if (Event.button.button != SDL_BUTTON_LEFT) break;
        for (auto& piece : Unit_)
          if (Board_.Xcood(Event.motion.x) == Board_.Xcood(piece.GetX()) &&
              Board_.Ycood(Event.motion.y) == Board_.Ycood(piece.GetY())) {
            Selected = &piece;

            // assign old position for piece
            beforeX = Selected->GetX();
            beforeY = Selected->GetY();
            

           
          }
        if (GoodMove_) {
          std::cout << "Goodmove";
        } else if (!GoodMove_) {
          std::cout << "wrong move";
        }
      }

      break;
      case SDL_MOUSEBUTTONUP:
        if (Event.button.button == SDL_BUTTON_LEFT) {
          // intergrate into unit class
          
          Selected = nullptr;
          if (Board_.GridX(targetX) != Board_.GridX(beforeX) or
              Board_.GridY(targetY) != Board_.GridY(beforeY)) {
            if (CurrentPlayer == 'W' && WhiteTurn) {
              WhiteTurn = false;
            }
            if (CurrentPlayer == 'B' && !WhiteTurn) {
              WhiteTurn = true;
            };
          }
        }
        break;
    }
  

  if (Selected) {
    // set new target positions for the piece
    if (Selected->Color_ == Unit::WHITE) {
      CurrentPlayer = 'W';
      std::cout << "white units selected";
      GoodMove_ =
          Logic_.WhiteMoveGood(Selected, Event.motion.x, Event.motion.y, beforeX, beforeY);
    };
    if (Selected->Color_ == Unit::BLACK) {
      CurrentPlayer = 'B';
      std::cout << "black units selected";
    };

	if (GoodMove_) {
    
    Selected->SetX(Board_.GridX(Board_.Xcood(Event.motion.x)));
    Selected->SetY(Board_.GridY(Board_.Ycood(Event.motion.y)));
    }
	std::cout << "dX ->" << dx << "dY ->" << dy << std::endl;
       
	
    // new position
    targetX = beforeX + dx;
    targetY = beforeY + dy;
    // change in position
    dx = Selected->GetX() - beforeX;
    dy = Selected->GetY() - beforeY;
    Selected->newX = targetX;
    Selected->newY = targetY;
  }
  }
}
