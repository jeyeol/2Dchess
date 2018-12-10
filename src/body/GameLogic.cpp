#include "src/header/GameLogic.h"
#include "pch.h"


GameLogic::GameLogic() {}

GameLogic::~GameLogic() {}

bool GameLogic::WhiteMoveGood(std::vector<Unit> &WUnit_) {
  
  char letter[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}; // letter grid
  int offSet = 56; // size of the grid
  
  for (auto& piece : WUnit_) {
    WCheckMove = &piece;
    bool InitPosition;
	//defining if the piece is in starting position or not
    if (WCheckMove->GetY() == WCheckMove->newY &&
        WCheckMove->GetX() == WCheckMove->newX) { InitPosition = true;} else {!InitPosition;}
    // case whitePawn
    if (WCheckMove->Color_ == Unit::WHITE && WCheckMove->UnitType_ == Unit::PAWN) { 
	  // start point can move either 2 or 1 grid;
      while (InitPosition)
        if ((Board_.Ycood(WCheckMove->GetY()) == Board_.Ycood(WCheckMove->oldY - 2 * offSet) or  Board_.Ycood(WCheckMove->GetY()) ==
                 Board_.Ycood(WCheckMove->oldY - offSet)) &&
            Board_.Ycood(WCheckMove->GetX()) == Board_.Ycood(WCheckMove->oldX)) { return true;} else { return false;}
	  // non starting position can only move 1 grid
	  while (!InitPosition)
        if (Board_.Ycood(WCheckMove->GetY()) == Board_.Ycood(WCheckMove->oldY - offSet) && Board_.Ycood(WCheckMove->GetX()) == Board_.Ycood(WCheckMove->oldX)) {
          return true;} else { return false; }
	}
	// case for  knight
	if (WCheckMove->Color_ == Unit::WHITE && WCheckMove->UnitType_ == Unit::KNIGHT)
	{
		// knight can move upto 2 y grid and 1 x grid
          if (abs(WCheckMove->GetY() - WCheckMove->oldY) == 2*offSet &&
              abs(WCheckMove->GetX() - WCheckMove->GetX) == offSet) {return true;} else {return false; };
    }
	// case for Bishop it moves diagonally 
	for (int i=0; i<7; i++)
		if (WCheckMove->Color_ == Unit::WHITE && WCheckMove->UnitType_ == Unit::BISHOP)
		{
            if (abs(WCheckMove->GetY() - WCheckMove->oldY) == (i+1)*offSet &&
                      abs(WCheckMove->GetX() - WCheckMove->GetX) ==
                          (i + 1) * offSet) {
                    return true;
            } else {
              return false;
            }
		}
	// case for rook. it only moves linearly
        for (int i=0; i<7; i++)
          if (WCheckMove->Color_ == Unit::WHITE && WCheckMove ->UnitType_ == Unit::ROOK) {
            if (abs(WCheckMove->GetY() - WCheckMove->oldY) ==
                    (i + 1) * offSet or
                abs(WCheckMove->GetX() - WCheckMove->GetX) ==
                    (i + 1) * offSet) {
              return true;
            } else {
              return false;
            }
          }
	// case for queen. it can move diagonally or linearly
        for (int i=0; i< 7; i++)
			if (WCheckMove->Color_ == Unit::WHITE &&
				WCheckMove->UnitType_ == Unit::QUEEN) {
            if (abs(WCheckMove->GetY() - WCheckMove->oldY) ==
                    (i + 1) * offSet &&
                abs(WCheckMove->GetX() - WCheckMove->GetX) ==
                    (i + 1) * offSet) {
              return true;
            } else if (abs(WCheckMove->GetY() - WCheckMove->oldY) ==
                           (i + 1) * offSet or
                       abs(WCheckMove->GetX() - WCheckMove->GetX) ==
                           (i + 1) * offSet) {
              return true;
            } else {
              return false;
            }

		  }
		// case for king. it can move only 1 tiles in every direction
        if (WCheckMove->Color_ == Unit::WHITE &&
            WCheckMove->UnitType_ == Unit::KING) {
          if (abs(WCheckMove->GetY() - WCheckMove->oldY) == 1 or
              abs(WCheckMove->GetX() - WCheckMove->oldX) == 1) {
            return true;
          } else {
            return false;
          }       
		  
        }
		

    
  }
}


