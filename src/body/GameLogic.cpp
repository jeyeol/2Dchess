#include "pch.h"
#include "src/header/GameLogic.h"

GameLogic::GameLogic() {}

GameLogic::~GameLogic() {}

bool GameLogic::WhiteMoveGood(Unit* WUnit_, int targetX, int targetY,
                              int beforeX, int beforeY) {
  int offset = 56;
  bool InitPosition;
  char gridX[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
  while (WUnit_->Color_ == Unit::WHITE) 
	  switch (WUnit_->UnitType_) {
      case Unit::PAWN: {
        if (Board_.Ycood(beforeY) == 7) {
          InitPosition = true;
        } else {
          InitPosition = false;
        }  // check to see if the pawn is in starting position

        while (InitPosition) {
          for (int i = 1; i < 3; i++)
            if (Board_.Ycood(targetY) == (Board_.Ycood(beforeY) - i) &&
                Board_.Xcood(targetX) == Board_.Xcood(beforeX)) {
              std::cout << "pawn Good move" << std::endl;
              return true;
            } else {
              return false;
              std::cout << "pawn wrong move";
            }  // case of init position can move either 2 or 1 grid up
        }
        break;
        while (!InitPosition) {
          if (Board_.Ycood(targetY) == (Board_.Ycood(beforeY) - 1) &&
              Board_.Xcood(targetX) == Board_.Xcood(beforeX)) {
            return true;
          } else {
            return false;
          }
        }
        break;
          // if not in init position can only move 1 up}
        case Unit::KNIGHT: {
          if (Board_.Xcood(abs(targetX- beforeX)) == gridX[1] &&
              abs(Board_.Ycood(targetY) - Board_.Ycood(beforeY)) == 2) {
            return true;
            std::cout << "knight right move";
          } else {
            return false;
            std::cout << "knight wrong move";
          }  // it basically move 2 units vertically and 1 units laterally
        }
      } break;
      case Unit::ROOK: {
        for (int i = 0; i < 8; i++) {
          if (Board_.Xcood(targetX) == Board_.Xcood(beforeX) &&
              abs(Board_.Ycood(targetY) - Board_.Ycood(beforeY)) == i) {
            return true;
          } else if (Board_.Ycood(targetY) == Board_.Ycood(beforeY) &&
                     Board_.Xcood(targetX - beforeY) == gridX[i]) {
            return true;
          } else {
            return false;
          }
        }
      } break;

      default:
        break;
    }
}

bool GameLogic::BlackMoveGood(Unit* BUnit_, int targetX, int targetY,
                              int beforeX, int beforeY) {
  return true;
}
