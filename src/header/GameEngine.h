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
		
private:
	Texture tex_;
	InputProcessing Input_;
	Board Board_;
	SDL_Renderer* m_Rend;
	SDL_Window* m_Window;
	//set of Unit class variables for each units
private:
	//unit vectors for white pieces...
	std::vector<Unit>wPawn[8];
	std::vector<Unit>wBishop[2];
	std::vector<Unit>wRook[2];
	std::vector<Unit>wKnight[2];
	std::vector<Unit>wKing;
	std::vector<Unit>wQueen;
	//unit vectors for black pieces...
	std::vector<Unit>bPawn[8];
	std::vector<Unit>bBishop[2];
	std::vector<Unit>bRook[2];
	std::vector<Unit>bKnight[2];
	std::vector<Unit>bKing;
	std::vector<Unit>bQueen;
private:
	SDL_Texture * t_board;
	SDL_Texture* t_unit;
	
};

