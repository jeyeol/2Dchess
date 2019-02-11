#include "pch.h"
#include "src/header/Board.h"
Board::Board() {}

Board::~Board() {}

int Board::GridCood(int x, int y) { return Calc(x) + 8*(Calc(y)-1); }

glm::vec2 Board::PixelCood(int gridNumber) {
 
  int xCood, yCood;
 
    xCood = ConvertGridX(gridNumber);  // column number
    yCood = ConvertGridY(gridNumber);  // row number
 
  cood.x = origin + offset * (xCood - 1);  //calculate x pixcel number
  cood.y = origin + offset * (yCood - 1); // calculate y pixcel number
  return cood;
}

int Board::Calc(int coordinate) {  // convert x pixcel cood to grid
  if (coordinate < 420) {
    return 1 + (coordinate - origin) / offset;
  }
  if (coordinate > 420 || coordinate ==420) {
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

glm::vec2 Board::DeadUnitSpace(Unit* Unit_, std::vector<Unit*> WholePiece) {
  DeadUnitCood_.x = 0;
  DeadUnitCood_.y = 523;
  return DeadUnitCood_;
  
}

int Board::DeadRoomNumber(Unit* Unit_, std::vector<Unit*> WholePiece) {	
int Room = 1;
  return Room;
}