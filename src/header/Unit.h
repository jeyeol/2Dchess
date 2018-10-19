#pragma once
//unit class uses for set and update coordinate of pieces

class Unit {
public:
	Unit() {};
	Unit(int x, int y) : x_(x), y_(y) {  };
	inline int SetX(int x) { x_ = x; };
	inline int SetY(int y) { y_ = y; };
	inline int GetX() { return x_; };
	inline int GetY() { return y_; };
	
private:
	int x_, y_;
};

