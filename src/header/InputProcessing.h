#pragma once
#include <iostream>
#include <vector>
#include "GameLogic.h"
#include "dep/include/SDL2/SDL.h"
#include "dep/include/glm/glm/glm.hpp"
#include "pch.h"
#include "src/header/Board.h"
#include "src/header/Unit.h"

class InputProcessing {
 public:
  InputProcessing();
  ~InputProcessing();
  bool WhiteTurn = true;
  void MouseInput(std::vector<Unit>& Unit_, std::vector<Unit*> WholePiece_);

 private:
  Unit* Selected = nullptr;
  Unit* Position = nullptr;
  SDL_Event Event;
  GameLogic Logic_;
  Board Board_; 
 private:

  int mouseGrid;
  int BeforeGrid_;
  int AfterGrid_;
  int ChangeGrid_;
  int CurrentGrid_;
  bool turnChange = false;
  char CurrentPlayer = 'W';
  bool InBoard_;
  bool GoodMove_ = false;
  bool ButtonDown_;
  int TurnWhite_;
};