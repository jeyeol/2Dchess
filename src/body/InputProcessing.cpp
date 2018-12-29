#include "pch.h"
#include "src/header/InputProcessing.h"


InputProcessing::InputProcessing() {}

InputProcessing::~InputProcessing() {}

void InputProcessing::MouseInput(std::vector<Unit>& Unit_,
                                 std::vector<Unit*> WholePiece_) {
  while (SDL_PollEvent(&Event)) {
    switch (Event.type) {
      case SDL_MOUSEBUTTONDOWN:
      {
        if (Event.button.button != SDL_BUTTON_LEFT) break;
        for (auto& piece : Unit_)
          if (Board_.GridCood(Event.motion.x, Event.motion.y) ==
              piece.Getgrid()) {
            Selected = &piece;
                                
            // assign old position for piece
            BeforeGrid_ = Selected->Getgrid();
           
          }

      }

      break;
      case SDL_MOUSEBUTTONUP:
        if (Event.button.button == SDL_BUTTON_LEFT) {
          // intergrate into unit class
          Selected = nullptr;
          if (AfterGrid_ != BeforeGrid_) {
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
      };
      if (Selected->Color_ == Unit::BLACK) {
        CurrentPlayer = 'B';
      };
      
      GoodMove_ = Logic_.MoveGood(
          Selected, Board_.GridCood(Event.motion.x, Event.motion.y)
          , BeforeGrid_, WholePiece_);
      std::cout << "Target Grid is -> "
                << Board_.GridCood(Event.motion.x, Event.motion.y);
      
      if (GoodMove_) {
        std::cout << "Good Move" << std::endl;
        Selected->Setgrid(Board_.GridCood(
          Event.motion.x,
          Event.motion.y));  // convert mouse position-> grid then set the grid
		}
      // change in position
      ChangeGrid_ = Selected->Getgrid() - BeforeGrid_;  // change in grid number
      AfterGrid_ = BeforeGrid_ + ChangeGrid_;           // new grid number
      Selected->SetNewgrid(
          AfterGrid_);  // save the new grid number to unit variable
    }
  }
}