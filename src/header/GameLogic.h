#pragma once
#include "pch.h"
#include "Board.h"
#include "Unit.h"
#include <vector>
#include <iostream>

class GameLogic
{
public:
	GameLogic();
	~GameLogic();
    bool WhiteMoveGood(Unit* WUnit_, int x, int y);
	bool BlackMoveGood(std::vector<Unit>& BUnit_);    

private:
	Board Board_;
	Unit* WCheckMove= nullptr;
	Unit* BCheckMove = nullptr;
	bool GoodMove_;   
   
};

