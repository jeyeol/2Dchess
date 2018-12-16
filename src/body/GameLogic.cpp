#include "pch.h"
#include "src/header/GameLogic.h"

GameLogic::GameLogic() {}

GameLogic::~GameLogic() {}

bool GameLogic::WhiteMoveGood(Unit* WUnit_, int x, int y) {

  while (WUnit_->Color_ == Unit::WHITE) {
    if (WUnit_->UnitType_== Unit::PAWN && Board_.Ycood(y) == (Board_.Ycood(WUnit_->oldY) + 2) &&
        Board_.Xcood(x) == Board_.Xcood(WUnit_->oldX)) {
      std::cout << "Good move" << std::endl;
      return true;
    } else {
      return false;
      std::cout << "wrong move";
    }
  }
}

bool GameLogic::BlackMoveGood(std::vector<Unit>& BUnit_) { return true; }
