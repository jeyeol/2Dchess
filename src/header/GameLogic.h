#pragma once
#include "InputProcessing.h"

class GameLogic
{
public:
	GameLogic();
	~GameLogic();
	bool WhiteMoveGood(std::vector<Unit>& WUnit_);
	bool BlackMoveGood(std::vector<Unit>& BUnit_);
private:
	Board Board_;
	Unit* WCheckMove= nullptr;
	Unit* BCheckMove = nullptr;
	bool GoodMove_;
};

