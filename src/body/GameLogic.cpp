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
                         std::vector<Unit*> WholePiece, int CurrentGrid) {
  PathOccupied_ = PathOccupied(Unit_, targetGrid, beforeGrid, WholePiece, 
                               CurrentGrid);

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
      if (!PathOccupied_)
        return BishopMove(Unit_, DeltaX, DeltaY);
      else
        return false;
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
      std::cout << DeltaGrid << std::endl;
      if (targetGrid == beforeGrid - 8 || targetGrid == beforeGrid - 16)
        return true;
      else
        return false;
    }
    if (!InitPosition_) {
      if (targetGrid == beforeGrid - 8)
        return true;
      else
        return false;
    }
  }
  if (Unit_->Color_ == Unit::BLACK) {
    if (InitPosition_) {
      std::cout << DeltaGrid << std::endl;
      if (targetGrid == beforeGrid + 8 || targetGrid == beforeGrid + 16)
        return true;
      else
        return false;
    }
    if (!InitPosition_) {
      if (targetGrid == beforeGrid + 8)
        return true;
      else
        return false;
    }
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
                             std::vector<Unit*> WholePiece, int CurrentGrid) {
  int Delta = targetGrid - beforeGrid;
  int DeltaX = Board_.ConvertGridX(targetGrid) -
               Board_.ConvertGridX(beforeGrid);  // columhn number
  int DeltaY = Board_.ConvertGridY(targetGrid) -
               Board_.ConvertGridY(beforeGrid);  // row number

  switch (Unit_->UnitType_) {
    case Unit::PAWN:
      for (auto* OtherUnit : WholePiece) {
        if (Unit_->Color_ == Unit::WHITE) {
          if (Delta == 0) return false;
          if (targetGrid == OtherUnit->Getgrid()) return true;
        }  // only in case of before capturing the units
        if (Unit_->Color_ == Unit::BLACK) {
          if (Delta == 0) return false;
          if (targetGrid == OtherUnit->Getgrid()) return true;
        }  // only in case of before capturing the units
      }
      return false;
      break;
    case Unit::BISHOP:

      Delta % 9 == 0 ? UnitMoved_ = 9 : UnitMoved_ = 7;
      if (Delta < 0) UnitMoved_ = UnitMoved_ * -1;
      std::cout << "Before Grid is now -> " << beforeGrid << std::endl;
      std::cout << "Target Grid is now -> " << targetGrid << std::endl;
      std::cout << "Delta / Unit moved_ -> " << Delta / UnitMoved_ << std::endl;
      std::cout << "Delta -> " << Delta << std::endl;
      std::cout << "UnitMOved is -> " << UnitMoved_ << std::endl;
      std::cout << "current position ->" << Unit_->Getgrid() << std::endl;
      std::cout << "Target grid is -> " << targetGrid << std::endl;
      if (!BishopMove(Unit_, DeltaX, DeltaY)) {
        return true;
      }
      for (auto* OtherUnit : WholePiece) {
        if (Delta == 0) return false;
        if (targetGrid == OtherUnit->Getgrid()) {
          std::cout << "same poisiton!";
          return true;
        }  // cant superimpose with other units
        DeltaUnit_ = Delta / UnitMoved_;

        if (BishopMove(Unit_, DeltaX, DeltaY)) {
          for (int i = 1; i < DeltaUnit_ ; i++) {           
            if (targetGrid - i * UnitMoved_ == OtherUnit->Getgrid()) {
              std::cout << "Path block" << std::endl;
              std::cout << "Blocked at ->" << OtherUnit->Getgrid() << std::endl;
              return true;
              break;
            }
            std::cout << "i is ->" << i << std::endl;
          }
        }
      }
      return false;
      break;

    default:
      if (Delta == 0) return false;
      return false;
  }
}

bool GameLogic::Tilefilled(Unit* Unit_, std::vector<Unit*> WholePiece,
                           int TargetGrid) {
  for (auto* OtherUnit : WholePiece) {
    if (TargetGrid == OtherUnit->Getgrid()) {
      return true;
    } else if (TargetGrid != OtherUnit->Getgrid())
      return false;
  }
}