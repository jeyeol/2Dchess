#include "pch.h"
#include "src/header/Board.h"

Board::Board()
{
}


Board::~Board()
{
}
//convert pixel location to letter location of the board (column letter, X)
int Board::GridX(char letter)
{
	if (letter == 'A') { return 28; };
	if (letter == 'B') { return 28 + offset; };
	if (letter == 'C') { return 28 + offset * 2; };
	if (letter == 'D') { return 28 + offset * 3; };
	if (letter == 'E') { return 28 + offset * 4; };
	if (letter == 'F') { return 28 + offset * 5; };
	if (letter == 'G') { return 28 + offset * 6; };
	if (letter == 'H') { return 28 + offset * 7; };
}
//convert pixel location to row location of the board (row number, Y)
int Board::GridY(int ycoord)
{
	return 28 + offset * (ycoord - 1);
}