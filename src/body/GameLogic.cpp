#include "pch.h"
#include "src/header/GameLogic.h"

GameLogic::GameLogic() {}

GameLogic::~GameLogic() {}

bool GameLogic::InitPosition(
    Unit* Unit_,
    int beforeGrid) {  // check to see it the Unit is in starting position
  if (Unit_->Color_ == Unit::WHITE && Unit_->UnitType_ == Unit::PAWN) {
    return beforeGrid > 48 && beforeGrid < 65;
  }
  if (Unit_->Color_ == Unit::BLACK && Unit_->UnitType_ == Unit::PAWN) {
    return beforeGrid > 8 && beforeGrid < 17;
  }
  return false;
}

bool GameLogic::MoveGood(Unit* Unit_, int targetGrid, int beforeGrid) {
  switch (Unit_->UnitType_) {
    case Unit::PAWN:
      return PawnMove(Unit_, targetGrid, beforeGrid);
      break;
    case Unit::ROOK:
      return RookMove(Unit_, targetGrid, beforeGrid);
      break;
    case Unit::BISHOP:
      return BishopMove(Unit_, targetGrid, beforeGrid);
      break;
    case Unit::KNIGHT:
      return KnightMove(Unit_, targetGrid, beforeGrid);
      break;
    case Unit::QUEEN:
      return QueenMove(Unit_, targetGrid, beforeGrid);
    case Unit::KING:
      return KingMove(Unit_, targetGrid, beforeGrid);
      break;  
  }
}

bool GameLogic::PawnMove(Unit* Unit_, int targetGrid, int beforeGrid) {
  InitPosition_ = InitPosition(
      Unit_, beforeGrid);  // check to see if the pawn is in init position
  int DeltaGrid = targetGrid - beforeGrid;  // change in grid
  if (Unit_->Color_ == Unit::WHITE) {       // case of white pawns//
    if (InitPosition_) return DeltaGrid == -8 || DeltaGrid == -16;
    if (!InitPosition_) return DeltaGrid == -8;
  }
  if (Unit_->Color_ == Unit::BLACK) {
    if (InitPosition_) return DeltaGrid == 8 || DeltaGrid == 16;
    if (!InitPosition_) return DeltaGrid == 8;
  }
}

bool GameLogic::RookMove(Unit* Unit_, int targetGrid, int beforeGrid) {
  int Dx = Board_.ConvertGridX(targetGrid) -
           Board_.ConvertGridX(beforeGrid);  // column number
  int Dy = Board_.ConvertGridY(targetGrid) -
           Board_.ConvertGridY(beforeGrid);  // row number
  return Dx == 0 || Dy == 0;
}

bool GameLogic::BishopMove(Unit* Unit_, int targetGrid, int beforeGrid) {
  int Dx = Board_.ConvertGridX(targetGrid) -
           Board_.ConvertGridX(beforeGrid);  // column number
  int Dy = Board_.ConvertGridY(targetGrid) -
           Board_.ConvertGridY(beforeGrid);  // row number
  return Dx == Dy || Dx == -Dy;
}
bool GameLogic::KnightMove(Unit* Unit_, int targetGrid, int beforeGrid) {
  int Dx = Board_.ConvertGridX(targetGrid) -
           Board_.ConvertGridX(beforeGrid);  // column number
  int Dy = Board_.ConvertGridY(targetGrid) -
           Board_.ConvertGridY(beforeGrid);  // row number
  return Dx * Dx + Dy * Dy == 5;
}
bool GameLogic::QueenMove(Unit* Unit_, int targetGrid, int beforeGrid) {
  int Dx = Board_.ConvertGridX(targetGrid) -
           Board_.ConvertGridX(beforeGrid);  // column number
  int Dy = Board_.ConvertGridY(targetGrid) -
           Board_.ConvertGridY(beforeGrid);  // row number
  return Dx == 0 || Dy == 0 || Dx == Dy || Dx == -Dy;
}
bool GameLogic::KingMove(Unit* Unit_, int targetGrid, int beforeGrid) {
  int Dx = Board_.ConvertGridX(targetGrid) -
           Board_.ConvertGridX(beforeGrid);  // column number
  int Dy = Board_.ConvertGridY(targetGrid) -
           Board_.ConvertGridY(beforeGrid);  // row number
  return Dx * Dx + Dy * Dy == 2 || Dx * Dx + Dy * Dy == 1;
}
