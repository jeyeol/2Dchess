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
}

bool GameLogic::MoveGood(Unit* Unit_, int targetGrid, int beforeGrid,
                         std::vector<Unit*> WholePiece) {

  PathOccupied_ = PathOccupied(Unit_, targetGrid, beforeGrid, WholePiece);

  int DeltaX = Board_.ConvertGridX(targetGrid) -
               Board_.ConvertGridX(beforeGrid);  // columhn number
  int DeltaY = Board_.ConvertGridY(targetGrid) -
               Board_.ConvertGridY(beforeGrid);  // row number

  switch (Unit_->UnitType_) {
    case Unit::PAWN:
      if (!PathOccupied_)
        return PawnMove(Unit_, targetGrid, beforeGrid);
      else
        return false;
      break;
    case Unit::ROOK:
      return RookMove(Unit_, DeltaX, DeltaY);
      break;
    case Unit::BISHOP:
      return BishopMove(Unit_, DeltaX, DeltaY);
      break;
    case Unit::KNIGHT:
      return KnightMove(Unit_, DeltaX, DeltaY);
      break;
    case Unit::QUEEN:
      return QueenMove(Unit_, DeltaX, DeltaY);
    case Unit::KING:
      return KingMove(Unit_, DeltaX, DeltaY);
      break;
  }
}

bool GameLogic::PawnMove(Unit* Unit_, int targetGrid, int beforeGrid) {
  InitPosition_ = InitPosition(
      Unit_, beforeGrid);  // check to see if the pawn is in init position
  int DeltaGrid = targetGrid - beforeGrid;  // change in grid
  if (Unit_->Color_ == Unit::WHITE) {       // case of white pawns//
    if (InitPosition_) {
      return DeltaGrid == -16;  
    }            
    else
      return DeltaGrid == -8;
  }
  if (Unit_->Color_ == Unit::BLACK) {
    if (InitPosition_)
      return DeltaGrid == 16;
    else
      return DeltaGrid == 8;
  }
}

bool GameLogic::RookMove(Unit* Unit_, int Dx, int Dy) {
  return Dx == 0 || Dy == 0;
}

bool GameLogic::BishopMove(Unit* Unit_, int Dx, int Dy) {
  return Dx == Dy || Dx == -Dy;
}
bool GameLogic::KnightMove(Unit* Unit_, int Dx, int Dy) {
  return Dx * Dx + Dy * Dy == 5;
}
bool GameLogic::QueenMove(Unit* Unit_, int Dx, int Dy) {
  return Dx == 0 || Dy == 0 || Dx == Dy || Dx == -Dy;
}
bool GameLogic::KingMove(Unit* Unit_, int Dx, int Dy) {
  return Dx * Dx + Dy * Dy == 2 || Dx * Dx + Dy * Dy == 1;
}

bool GameLogic::PathOccupied(Unit* Unit_, int targetGrid, int beforeGrid,
                             std::vector<Unit*> WholePiece) {
  switch (Unit_->UnitType_) {
    case Unit::PAWN:
      for (auto* OtherUnit : WholePiece) {
        if (Unit_->Color_ == Unit::WHITE) {
          if (beforeGrid - 8 == OtherUnit->Getgrid()) return true;
        }
        if (Unit_->Color_ == Unit::BLACK) {
          if (beforeGrid + 8 == OtherUnit->Getgrid()) return true;
        }
      }
      return false;
      break;

    default:
      return false;
  }
}