#include "pch.h"
#include "src/header/Board.h"

Board::Board() {}
Board::~Board() {}

int Board::GridCood(int x, int y) { return Calc(x) + 8 * (Calc(y) - 1); }

glm::vec2 Board::PixelCood(int gridNumber) {
  int xCood, yCood;
  if (gridNumber < 99) {
    xCood = ConvertGridX(gridNumber);        // column number
    yCood = ConvertGridY(gridNumber);        // row number
    cood.x = origin + offset * (xCood - 1);  // calculate x pixcel number
    cood.y = origin + offset * (yCood - 1);  // calculate y pixcel number
    return cood;
  }
  //below is for dead unit room
  if (gridNumber > 99) { 
    if (gridNumber > 99 and gridNumber < 108) {
    cood.x = (gridNumber - 100) * 56;
    cood.y = 579;
    return cood;
  } else if (gridNumber>107 and gridNumber<116) {
    cood.x = (gridNumber - 108) * 56;
    cood.y = 635;
    return cood;
  } // dead space for white
  else if (gridNumber > 115 and gridNumber < 124) {
    cood.x = (gridNumber - 116) * 56;
    cood.y = 691;
    return cood;
  } else if (gridNumber > 123 and gridNumber < 132) {
    cood.x = (gridNumber - 124) * 56;
    cood.y = 747;
    return cood;
  } // dead space for black
}
}

int Board::Calc(int coordinate) {  // convert x pixcel cood to grid
  if (coordinate < 420) {
    return 1 + (coordinate - origin) / offset;
  }
  if (coordinate > 420 || coordinate == 420) {
    return 8;
  }
}

int Board::ConvertGridX(
    int gridNumber) {  // find out column number from the grid
  if (gridNumber % 8 == 0) {
    return 8;
  } else {
    return gridNumber % 8;
  }
}
int Board::ConvertGridY(int gridNumber) {  // find out row number from the grid
  if (gridNumber % 8 == 0) {
    return gridNumber / 8;
  } else {
    return gridNumber / 8 + 1;
  }
}

glm::vec2 Board::DeadUnitSpace(Unit* Unit_, std::vector<Unit*> WholePiece,
                               int RoomNumber) {
  DeadUnitCood_.x = 0;
  DeadUnitCood_.y = 523;
  return DeadUnitCood_;
}

int Board::DeadRoomNumber(Unit* Unit_, std::vector<Unit*> WholePiece) {
  int Room = 1;
  return Room;
}