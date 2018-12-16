#pragma once
#include "src/header/Texture.h"
#include "src/header/Board.h"
#include "src/header/Unit.h"
#include "src/header/InputProcessing.h"
#include <vector>


class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	void Engine();
	void PositionUpdate();
	void InitWindowandRenderer();
	void RenderTexture();
	void CreateSurfaceandTexture();
	void UnitVectorsInit();
	
	
	
private: //class objects
	Texture tex_;
	InputProcessing Input_;
	Board Board_;
    Unit Unit_;
	InputProcessing* WhiteTurn_;
    GameLogic Logic_;

   private: //sdl objects
	SDL_Renderer* m_Rend; //sdl renderer
	SDL_Window* m_Window; //sdl window
	SDL_Texture * t_board; //texture for board
	SDL_Texture* t_unit; // textures for units
	SDL_Texture* t_UItexture; //texture UI
	
private: //std:: vectors
	std::vector<Unit> wUnits; //position of white pieces
	std::vector<Unit> bUnits; //position of black pieces
	
};

