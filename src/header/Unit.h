#pragma once

// unit class uses for set and update coordinate of pieces
class Unit {
 public:
  enum PlayerColor { WHITE, BLACK };
  enum UnitType { PAWN, ROOK, KING, QUEEN, BISHOP, KNIGHT };

  Unit(){};
  Unit(int gridnumber, PlayerColor Color, UnitType UnitType)
      : number_(gridnumber),
        oldgrid_(gridnumber),
        newgrid_(gridnumber),
        Color_(Color),
        UnitType_(UnitType){};

  inline int Setgrid(int number) {
    number_ = number;
    return number_;
  };
  inline int Getgrid() { return number_; };
  inline int GetOldgrid() { return oldgrid_; };
  inline int SetOldgrid(int number) {
    oldgrid_ = number;
    return oldgrid_;
  };
  inline int SetNewgrid(int number) {
    number = newgrid_;
    return newgrid_;
  };
  inline int Getoldgrid() { return oldgrid_; };
  UnitType UnitType_;
  PlayerColor Color_;

 private:
  int number_; // this is the variable for grid numbers
  int newgrid_;
  int oldgrid_;
};
