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
#include "GameLogic.h"

class InputProcessing
{
public:
	InputProcessing();
	~InputProcessing();
	bool WhiteTurn=true;
	void MouseInput(std::vector<Unit> &Unit_);
	
private:
	Unit* Selected =nullptr;
	Unit* Position = nullptr;
	SDL_Event Event;
        GameLogic Logic_;
		Board Board_;
	
	
private:
        int beforeX;
        int beforeY;
        int targetX;
        int targetY;
        int dx;
        int dy;
        bool turnChange = false;
        char CurrentPlayer = 'W';
        bool InBoard_;
        bool GoodMove_=false;
        
};
