#pragma once
#include "dep/include/SDL2/SDL.h"
#include "pch.h"
#include "src/header/InputProcessing.h"
#include "src/header/Unit.h"
#include <vector>
#include "src/header/Board.h"
#include <iostream>
#include "dep/include/glm/glm/glm.hpp"
#include "dep/include/glm/glm/glm.hpp"

class InputProcessing
{
public:
	InputProcessing();
	~InputProcessing();
	
	void MouseInput(std::vector<Unit> &Unit_, int piece);
	
private:
	bool isSelected = false;
	bool JustStarted = true;
	SDL_Event Event;
	int beforeX;
	int beforeY;
	int targetX;
	int targetY;
	Board Board_;
	

};
