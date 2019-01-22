#pragma once
#include <iostream>
#include <vector>
#include "Board.h"
#include "Unit.h"
#include "pch.h"
#include "dep/include/SDL2/SDL.h"

class GameLogic {
 public: //applies for the whole Unit. binder functions
  GameLogic();
  ~GameLogic();
  bool InitPosition(Unit* Unit_, int beforeGrid);
  bool MoveGood(Unit* Unit_, int targetGrid,
                int beforeGrid, std::vector<Unit*> WholePiece, int CurrentGrid); 
  bool PathOccupied(Unit* Unit_, int targetGrid, int beforeGrid,
                    std::vector<Unit*> WholePiece, int CurrentGrid);
  
  
 public: //control logic by piece
  bool PawnMove(Unit* Unit_, int targetGrid, int beforeGrid ); //process the logic of pawn
  bool RookMove(Unit* Unit_, int Dx,  int Dy);  // process the logic of rook
  bool BishopMove(Unit* Unit_, int Dx, int Dy);  // process the logic of bishop
  bool KnightMove(Unit* Unit_, int Dx, int Dy);
  bool KingMove(Unit* Unit_, int Dx, int Dy);
  bool QueenMove(Unit* Unit_, int Dx, int Dy);
  bool Tilefilled(Unit* Unit_, std::vector<Unit*> WholePiece, int TargetGrid);
  
  
 private:
  Board Board_;
  Unit* WCheckMove = nullptr;
  Unit* BCheckMove = nullptr;
  
  bool GoodMove_;
  bool InitPosition_ = false;
  bool CanKill_=false;
  bool Tilefilled_;
  bool EnemyOnTarget_; //check if the Enemy is blocking the way
  bool TeamOnTarget_; // check if the same team is block the way
  bool PathOccupied_;
  bool TargetOccupied_;
  int UnitMoved_=0; //how much units of movement does it goes (ie for bishop 1 scale diagoal)
  int DeltaUnit_ = 0;
  int Switch_=0;
  
};
