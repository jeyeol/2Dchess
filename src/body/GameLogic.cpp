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
  PathOccupied_ =
      PathOccupied(Unit_, targetGrid, beforeGrid, WholePiece, CurrentGrid);

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
      if (!PathOccupied_)
        return RookMove(Unit_, DeltaX, DeltaY);
      else
        return false;
      break;
    case Unit::BISHOP:
      if (!PathOccupied_)
        return BishopMove(Unit_, DeltaX, DeltaY);
      else
        return false;
      break;
    case Unit::KNIGHT:
      if (!PathOccupied_)
        return KnightMove(Unit_, DeltaX, DeltaY);
      else
        return false;
      break;
    case Unit::QUEEN:
      if (!PathOccupied_)
        return QueenMove(Unit_, DeltaX, DeltaY);
      else
        return false;
      break;
    case Unit::KING:
      if (!PathOccupied_)
        return KingMove(Unit_, DeltaX, DeltaY);
      else
        return false;
      break;
  }
}

bool GameLogic::PawnMove(Unit* Unit_, int targetGrid, int beforeGrid) {
  InitPosition_ = InitPosition(
      Unit_, beforeGrid);  // check to see if the pawn is in init position
  int DeltaGrid = targetGrid - beforeGrid;  // change in grid
  if (DeltaGrid == 0) return true; // make it to return its original position
  if (Unit_->Color_ == Unit::WHITE) {  // case of white pawns//
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
  return Dx == 0 || Dy == 0 || (Dx == 0 && Dy == 0);
}

bool GameLogic::BishopMove(Unit* Unit_, int Dx, int Dy) {
  return Dx == Dy || Dx == -Dy || (Dx == 0 && Dy == 0);
}
bool GameLogic::KnightMove(Unit* Unit_, int Dx, int Dy) {
  return Dx * Dx + Dy * Dy == 5 || (Dx == 0 && Dy == 0);
}
bool GameLogic::QueenMove(Unit* Unit_, int Dx, int Dy) {
  return Dx == 0 || Dy == 0 || Dx == Dy || Dx == -Dy || (Dx == 0 && Dy == 0);
}
bool GameLogic::KingMove(Unit* Unit_, int Dx, int Dy) {
  return Dx * Dx + Dy * Dy == 2 || Dx * Dx + Dy * Dy == 1 ||
         (Dx == 0 && Dy == 0);
}

bool GameLogic::PathOccupied(Unit* Unit_, int targetGrid, int beforeGrid,
                             std::vector<Unit*> WholePiece, int CurrentGrid) {
  int Delta = targetGrid - beforeGrid;
  int DeltaX = Board_.ConvertGridX(targetGrid) -
               Board_.ConvertGridX(beforeGrid);  // columhn number
  int DeltaY = Board_.ConvertGridY(targetGrid) -
               Board_.ConvertGridY(beforeGrid);  // row number
  int DistanceFromInitPoint = 0;
  int UnitChange = 0; // upper two variables are used for preventing changing the path during move for bishop, queen, rook

  switch (Unit_->UnitType_) {
    case Unit::PAWN:
      for (auto* OtherUnit : WholePiece) {
        if (Unit_->Color_ == Unit::WHITE) {
          if (targetGrid == OtherUnit->Getgrid()) return true;
        }  // only in case of before capturing the units
        if (Unit_->Color_ == Unit::BLACK) {
          if (targetGrid == OtherUnit->Getgrid()) return true;
        }  // only in case of before capturing the units
      }
      return false;
      break;
    case Unit::BISHOP:
      Delta = targetGrid - CurrentGrid;
      if (Delta % 9 == 0) {
        UnitMoved_ = 9;
      } else if (Delta % 7 == 0) {
        UnitMoved_ = 7;
      } else
        UnitMoved_ = 1;
      if (Delta < 0) UnitMoved_ = UnitMoved_ * -1;

      DistanceFromInitPoint = CurrentGrid - beforeGrid;
      DistanceFromInitPoint % 9 == 0 ? UnitChange = 9 : UnitChange = 7;
      if (DistanceFromInitPoint < 0)
        UnitChange =
            UnitChange *
            -1;  // this is the bug fixing for changing path during the move

      for (auto* OtherUnit : WholePiece) {
        if (Delta == 0) return false;
        if (CurrentGrid != beforeGrid) {
          if (abs(UnitChange) != abs(UnitMoved_)) return true;
        }  // change path bug fixing method
        if (targetGrid == OtherUnit->Getgrid()) {
          return true;
        }  // cant superimpose with other units

        DeltaUnit_ = Delta / UnitMoved_;
        if (BishopMove(Unit_, DeltaX, DeltaY)) {
          for (int i = 1; i < DeltaUnit_; i++) {
            if (targetGrid - i * UnitMoved_ == (OtherUnit->Getgrid())) {
              return true;
              break;
            }  // check the units in between the path
          }
        }
      }
      return false;
      break;
    case Unit::KNIGHT:
      for (auto* OtherUnit : WholePiece) {
        if (targetGrid == OtherUnit->Getgrid()) {
          return true;
        }  // cant superimpose with other units
        if (targetGrid == beforeGrid + 17 || targetGrid == beforeGrid + 15) {
          if (beforeGrid + 8 == OtherUnit->Getgrid()) {
            return true;
          }
        }
        if (targetGrid == beforeGrid - 17 || targetGrid == beforeGrid - 15) {
          if (beforeGrid - 8 == OtherUnit->Getgrid()) {
            return true;
          }
        }
        if (targetGrid == beforeGrid - 6 || targetGrid == beforeGrid + 10) {
          if (beforeGrid + 1 == OtherUnit->Getgrid()) {
            return true;
          }
        }
        if (targetGrid == beforeGrid - 10 || targetGrid == beforeGrid + 6) {
          if (beforeGrid - 1 == OtherUnit->Getgrid()) {
            return true;
          }
        }
      }
      return false;
      break;
    case Unit::KING:
      for (auto* OtherUnit : WholePiece) {
        if (targetGrid == OtherUnit->Getgrid()) {
          return true;
        }  // cant superimpose with other units
      }
      return false;
      break;
    case Unit::ROOK:

      Delta = targetGrid - CurrentGrid;

      if (Delta % 8 == 0) {
        UnitMoved_ = 8;
      } else if (DeltaY == 0 && abs(DeltaX) > 0 && abs(DeltaX) < 8) {
        UnitMoved_ = 1;
      } else
        UnitMoved_ = 0;

      DistanceFromInitPoint = CurrentGrid - beforeGrid;
      DistanceFromInitPoint % 8 == 0 ? UnitChange = 8 : UnitChange = 1;

      if (Delta < 0) UnitMoved_ = UnitMoved_ * -1;
      if (DistanceFromInitPoint < 0)
        UnitChange = UnitChange * -1;  // for path change bug fix line 236-238

      for (auto* OtherUnit : WholePiece) {
        if (Delta == 0) return false;

        if (targetGrid == OtherUnit->Getgrid()) {
          return true;
        }  // cant superimpose with other units

        if (CurrentGrid != beforeGrid) {
          if (abs(UnitChange) != abs(UnitMoved_)) return true;
        }  // change path bug fixing method bind to line 236-238

        DeltaUnit_ = Delta / UnitMoved_;
        if (RookMove(Unit_, DeltaX, DeltaY)) {
          for (int i = 1; i < DeltaUnit_; i++) {
            if (targetGrid - i * UnitMoved_ == OtherUnit->Getgrid()) {
              std::cout << "Path block at ->" << OtherUnit->Getgrid()
                        << std::endl;
              return true;
              break;
            }
          }
        }
      }
      return false;
      break;
    case Unit::QUEEN:
      Delta = targetGrid - CurrentGrid;
      DistanceFromInitPoint = CurrentGrid - beforeGrid;
      FinalDelta_ = targetGrid - beforeGrid;
      if (targetGrid == beforeGrid) return false;
      if (IsDiagonal_) std::cout << "Is Diagonal" << std::endl;
      if (!IsDiagonal_) std::cout << "Is NOt diagonal" << std::endl;
      if (FinalDelta_ % 9 == 0 || FinalDelta_ % 7 == 0) IsDiagonal_ = true;
      else
        IsDiagonal_ = false;

      for (auto* OtherUnit : WholePiece) {
        if (Delta == 0) return false;

        if (targetGrid == OtherUnit->Getgrid()) {
          return true;
        }  // cant superimpose with other units
	  }


	 if (QueenMove(Unit_, DeltaX, DeltaY)) {
            if (BishopMove(Unit_, DeltaX, DeltaY)) {
             
             Delta = targetGrid - CurrentGrid;
             FinalDelta_ = targetGrid - beforeGrid;

             if (RookMove(Unit_, DeltaX, DeltaY)) return true;
             if (Delta % 9 == 0) {
               UnitMoved_ = 9;
             } else if (Delta % 7 == 0) {
               UnitMoved_ = 7;
             } else
               UnitMoved_ = 1;
             if (Delta < 0) UnitMoved_ = UnitMoved_ * -1; 
			            
             DistanceFromInitPoint = CurrentGrid - beforeGrid;
             DistanceFromInitPoint % 9 == 0 ? UnitChange = 9 : UnitChange = 7;
             
			 if (DistanceFromInitPoint < 0)
               UnitChange = UnitChange * -1;  // this is the bug fixing for
                                              // changing path during the move

             for (auto* OtherUnit : WholePiece) {
               if (Delta == 0) return false;
               if (CurrentGrid != beforeGrid) {
                 if (abs(UnitChange) != abs(UnitMoved_)) return true;
               }  // change path bug fixing method
               if (targetGrid == OtherUnit->Getgrid()) {
                 return true;
               }  // cant superimpose with other units

               DeltaUnit_ = Delta / UnitMoved_;
               if (BishopMove(Unit_, DeltaX, DeltaY)) {
                 for (int i = 1; i < DeltaUnit_; i++) {
                   if (targetGrid - i * UnitMoved_ == (OtherUnit->Getgrid())) {
                     return true;
                     break;
                   }  // check the units in between the path
                 }
               }
             }
           }
            if (RookMove(Unit_, DeltaX, DeltaY)) {
             Delta = targetGrid - CurrentGrid;
             if (BishopMove(Unit_, DeltaX, DeltaY)) return true;
             if (Delta % 8 == 0) {
               UnitMoved_ = 8;
             } else if (DeltaY == 0 && abs(DeltaX) > 0 && abs(DeltaX) < 8) {
               UnitMoved_ = 1;
             } else
               UnitMoved_ = 4;

             DistanceFromInitPoint = CurrentGrid - beforeGrid;
             DistanceFromInitPoint % 8 == 0 ? UnitChange = 8 : UnitChange = 1;

             if (Delta < 0) UnitMoved_ = UnitMoved_ * -1;
             if (DistanceFromInitPoint < 0)
               UnitChange =
                   UnitChange * -1;  // for path change bug fix line 236-238

             for (auto* OtherUnit : WholePiece) {
               if (Delta == 0) return false;

               if (targetGrid == OtherUnit->Getgrid()) {
                 return true;
               }  // cant superimpose with other units

               if (CurrentGrid != beforeGrid) {
                 if (abs(UnitChange) != abs(UnitMoved_)) return true;
               }  // change path bug fixing method bind to line 236-238

               DeltaUnit_ = Delta / UnitMoved_;
               if (RookMove(Unit_, DeltaX, DeltaY)) {
                 for (int i = 1; i < DeltaUnit_; i++) {
                   if (targetGrid - i * UnitMoved_ == OtherUnit->Getgrid()) {
                     std::cout << "Path block at ->" << OtherUnit->Getgrid()
                               << std::endl;
                     return true;
                     break;
                   }
                 }
               }
             }
           }
          } 	   



      return false;
      break;
  }
}
