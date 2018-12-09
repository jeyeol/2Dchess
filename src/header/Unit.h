#pragma once

//unit class uses for set and update coordinate of pieces
class Unit {

public:
	enum PlayerColor {WHITE, BLACK};
	enum UnitType {PAWN, ROOK, KING, QUEEN, BISHOP, KNIGHT};
	Unit() {};
	Unit(int x, int y, PlayerColor Color ,UnitType UnitType) : x_(x), y_(y), oldX(x), oldY(y), newX(x), newY(y),Color_(Color), UnitType_(UnitType) {  };
	inline int SetX(int x) { x_ = x; return x_; };
	inline int SetY(int y) { y_ = y; return y_; };
	inline int GetX() { return x_; };
	inline int GetY() { return y_; };
	UnitType UnitType_;
	PlayerColor Color_;
	int oldX;
	int oldY;
	int newX;
	int newY;
private:
	int x_, y_;
	
};

