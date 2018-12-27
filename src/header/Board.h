#pragma once
#include "dep/include/glm/glm/glm.hpp"

class Board {
 public:
  Board();
  ~Board();
  int Board_[8][8];
  int GridCood(int x, int y);// gives grid coord
  glm::vec2 PixelCood(int gridNumber);
  int Calc(int coordinate);  //calcuate row and columm number
  int ConvertGridX(int gridNumber);
  int ConvertGridY(int gridNumber);

 private:
  int offset = 56;
  int origin = 28;
  int netX;
  int netY;
  glm::vec2 cood;
};
