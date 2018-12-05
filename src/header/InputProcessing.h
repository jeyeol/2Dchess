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
	
	void MouseInput(std::vector<Unit> &Unit_, int piece);

	bool isSelected = false;
	
private:
	bool JustStarted;
	SDL_Event Event;
	int beforeX;
	int beforeY;
	int targetX;
	int targetY;
	Board Board_;
	

};
