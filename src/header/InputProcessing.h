#pragma once
#include "dep/include/SDL2/SDL.h"
#include "pch.h"
#include "src/header/InputProcessing.h"
#include "src/header/Unit.h"
#include <vector>

class InputProcessing
{
public:
	InputProcessing();
	~InputProcessing();
	void MouseInput();
	int xTarget() { return xTarget_; };
	int yTarget() { return yTarget_; };
private:
	SDL_Event Event;
	int xbefore_;
	int ybefore_;
	int xTarget_;
	int yTarget_;
	Unit Unit_;
};

