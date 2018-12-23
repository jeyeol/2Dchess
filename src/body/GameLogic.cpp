#include "pch.h"
#include "src/header/GameLogic.h"


GameLogic::GameLogic() {}

GameLogic::~GameLogic() {}

bool GameLogic::WhiteMoveGood(Unit* WUnit_, int targetX, int targetY,
                              int beforeX, int beforeY) {
  int offset = 56;
  bool InitPosition;
  int dx, dy; // grid change in x and y
  
  dx = (targetX - beforeX) / offset; //plus is right and minus is left
  dy = -(targetY - beforeY) / offset; // plus is up and minus is down both make in 1 grid change
 
  
  while (WUnit_->Color_ == Unit::WHITE) switch (WUnit_->UnitType_) {
      case Unit::PAWN: {
        if (Board_.Ycood(beforeY)==7) {
          InitPosition = true;
          std::cout << "initposition";
        } else {
          InitPosition = false;
          std::cout << "not init position";
        }  // check to see if the pawn is in starting position
        while (InitPosition) {
          if (dx ==0 && dy == 2) {
            return true;
            std::cout << "Calculated dx -> " << dx << std::endl;
            std::cout << "calculated dy -> " << dy << std::endl;
          } else if (dx == 0 && dy == 1) {
            std::cout << "Calculated dx -> " << dx << std::endl;
            std::cout << "calculated dy -> " << dy << std::endl;
            return true;
          } else {
            return false;
          }
        }
        while (!InitPosition) {
          if (dx == 0 && dy == 1) {
            std::cout << "Calculated dx -> " << dx << std::endl;
            std::cout << "calculated dy -> " << dy << std::endl;
            return true;
          } else {
            return false;
          }
        }
        case Unit::ROOK: {
          while (dx == 0) {
            for (int i = 1; i < 8; i++) {
              if (dy == i) {
                return true;
              } else {
                return false;
              }
            }
          }
          while (dy == 0) {
            for (int i = -7; i < 8; i++) {
              if (dx == i && dx !=0) {
                return true;
              } else {
                return false;
              }
            }
          }
        }
      }

      default:
        break;
    }
}

bool GameLogic::BlackMoveGood(Unit* BUnit_, int targetX, int targetY,
                              int beforeX, int beforeY) {
  return true;
}
