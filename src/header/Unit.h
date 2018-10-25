#pragma once

//unit class uses for set and update coordinate of pieces
class Unit {
public:
	Unit() {};
	Unit(int x, int y) : x_(x), y_(y), TargetX_(x), TargetY_(y) {  };
	inline int SetX(int x) { x_ = x; return x_; };
	inline int SetY(int y) { y_ = y; return y_; };
	inline int GetX() { return x_; };
	inline int GetY() { return y_; };
	int TargetX_;
	int TargetY_;
private:
	int x_, y_;
};

