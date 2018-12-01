#pragma once
#include "dep/include/SDL2/SDL.h"
#include "pch.h"
#include "src/header/InputProcessing.h"
#include "src/header/Unit.h"
#include <vector>
#include "src/header/Board.h"
#include <iostream>
#include "dep/include/glm/glm/glm.hpp"

class InputProcessing
{
public:
	InputProcessing();
	~InputProcessing();
	
	void MouseInput(std::vector<Unit>&Unit_);

	bool isSelected = false;
	//inline int NewPosX(std::vector<Unit>&Unit_) { return targetX; };
	//inline int NewPosY(std::vector<Unit>&Unit_) { return targetY; };
private:
	bool JustStarted;
	SDL_Event Event;
	int beforeX;
	int beforeY;
	int targetX;
	int targetY;
	Board Board_;

};
