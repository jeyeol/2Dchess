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

char Board::Xcood(int x)// this function convert mouse x position to grid coordinate x
{
	if (x == 28  or x < 28 + offset){ return 'A'; };
	if (x == 28+offset or x < 28 + 2*offset) { return 'B'; };
	if (x == 28 + 2*offset or x < 28 + 3 * offset) { return 'C'; };
	if (x == 28 + 3*offset or x < 28 + 4 * offset) { return 'D'; };
	if (x == 28 + 4*offset or x < 28 + 5 * offset) { return 'E'; };
	if (x == 28 + 5*offset or x < 28 + 6 * offset) { return 'F'; };
	if (x == 28 + 6 * offset or x < 28 + 7 * offset) { return 'G'; };
	if (x == 28 + 7 * offset or x < 28 + 8 * offset) { return 'H'; };
}

int Board::Ycood(int y)// this function convert mouse y position to grid coordinate x
{
	return 1 + (y - 28) / 56;
}