#include "pch.h"
#include "src/header/GameLogic.h"

GameLogic::GameLogic() {}

GameLogic::~GameLogic() {}

bool GameLogic::WhiteMoveGood(Unit* WUnit_, int targetX, int targetY,
                              int beforeX, int beforeY) {
  int offset = 56;
  bool InitPosition;
  while (WUnit_->Color_ == Unit::WHITE && WUnit_->UnitType_ == Unit::PAWN) {
    if (Board_.Ycood(beforeY) == 7) {
      InitPosition = true;
    } else {
      InitPosition = false;
    } // check to see if the pawn is in starting position

    while(InitPosition) {
      for (int i=1; i<3; i++)
	if (Board_.Ycood(targetY) == (Board_.Ycood(beforeY) - i) &&
        Board_.Xcood(targetX) == Board_.Xcood(beforeX)) {
      std::cout << "Good move" << std::endl;
      return true;
    } else {
      return false;
      std::cout << "wrong move";
    }// case of init position can move either 2 or 1 grid up
	}
    while (!InitPosition) {
          if (Board_.Ycood(targetY) == (Board_.Ycood(beforeY) - 1) &&
          Board_.Xcood(targetX) == Board_.Xcood(beforeX)) {
        return true;
          } else {
            return false;
          }
        }
	// if not in init position can only move 1 up
  }
}

bool GameLogic::BlackMoveGood(std::vector<Unit>& BUnit_) { return true; }
