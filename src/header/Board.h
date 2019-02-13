#pragma once
#include <vector>
#include "Unit.h"
#include "dep/include/glm/glm/glm.hpp"
// convert position vector to grid cood and process
class Board {
 public:
  Board();
  ~Board();
  int Board_[8][8];
  int GridCood(int x, int y);  // gives grid coord
  glm::vec2 PixelCood(int gridNumber);
  int Calc(int coordinate);  // calcuate row and columm number
  int ConvertGridX(int gridNumber);
  int ConvertGridY(int gridNumber);
  glm::vec2 DeadUnitSpace(Unit* Unit_, std::vector<Unit*> WholePiece,
                          int RoomNumber);
  int DeadRoomNumber(Unit* Unit_, std::vector<Unit*> WholePiece);

 private:
  int offset = 56;
  int origin = 28;
  int netX;
  int netY;
  glm::vec2 cood;
  Unit Unit_;
  int DeadUnitRoom_;
  glm::vec2 DeadUnitCood_;
};