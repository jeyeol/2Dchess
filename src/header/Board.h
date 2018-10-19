#pragma once
class Board
{
public:
	Board();
	~Board();
	int Board_[8][8];
	int GridX(char letter);
	int GridY(int ycoord);
private:
	int offset = 56;
};
