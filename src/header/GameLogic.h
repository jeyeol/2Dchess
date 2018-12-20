#pragma once
#include <iostream>
#include <vector>
#include "Board.h"
#include "Unit.h"
#include "pch.h"

class GameLogic {
 public:
  GameLogic();
  ~GameLogic();
  bool WhiteMoveGood(Unit* WUnit_, int targetX, int targetY, int beforeX,
                     int beforeY);
  bool BlackMoveGood(Unit* BUnit_, int targetX, int targetY, int beforeX,
                     int beforeY);

 private:
  Board Board_;
  Unit* WCheckMove = nullptr;
  Unit* BCheckMove = nullptr;
  bool GoodMove_;
};
