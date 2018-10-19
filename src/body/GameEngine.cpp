#include "pch.h"
#include "src/header/GameEngine.h"


GameEngine::GameEngine()
{
	InitWindowandRenderer();
	UnitVectorsInit();
	CreateSurfaceandTexture();
}


GameEngine::~GameEngine()
{
	tex_.DeleteTexture(t_unit); tex_.DeleteTexture(t_board);
	SDL_DestroyRenderer(m_Rend); SDL_DestroyWindow(m_Window);
}


void GameEngine::InitWindowandRenderer()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialized..." << std::endl;
	}
	m_Window = SDL_CreateWindow("2D Chess Game!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 800, SDL_WINDOW_OPENGL);
	if (m_Window == nullptr)
	{
		std::cout << "window failed to initialized...." << std::endl;
	}
	//create renderer & render error code
	m_Rend = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
	if (m_Rend == nullptr)
	{
		std::cout << "Renderer failed to initialized...." << std::endl;
	}
	//background color setup
	SDL_SetRenderDrawColor(m_Rend, 0, 0, 0, 255);
}

void GameEngine::RenderTexture()
{
	//rendering the board
	SDL_RenderCopy(m_Rend, t_board, NULL, &tex_.ImageRect(0, 0, 504, 504));
	//rendering of units
	//white units
	for (int i = 0; i < 8; i++)
		SDL_RenderCopy(m_Rend, t_unit, &tex_.ImageRect(288, 58, 56, 56), &tex_.ImageRect(wPawn[i].back().GetX(), wPawn[i].back().GetY(), 56, 56));
	for (int i = 0; i < 2; i++)
	{
		SDL_RenderCopy(m_Rend, t_unit, &tex_.ImageRect(57, 58, 56, 56), &tex_.ImageRect(wKnight[i].back().GetX(), wKnight[i].back().GetY(), 56, 56));
		SDL_RenderCopy(m_Rend, t_unit, &tex_.ImageRect(57 * 2, 58, 56, 56), &tex_.ImageRect(wBishop[i].back().GetX(), wBishop[i].back().GetY(), 56, 56));
		SDL_RenderCopy(m_Rend, t_unit, &tex_.ImageRect(0, 58, 56, 56), &tex_.ImageRect(wRook[i].back().GetX(), wRook[i].back().GetY(), 56, 56));
	}
	SDL_RenderCopy(m_Rend, t_unit, &tex_.ImageRect(57 * 3, 58, 56, 56), &tex_.ImageRect(wKing.back().GetX(), wKing.back().GetY(), 56, 56));
	SDL_RenderCopy(m_Rend, t_unit, &tex_.ImageRect(57 * 4, 58, 56, 56), &tex_.ImageRect(wQueen.back().GetX(), wQueen.back().GetY(), 56, 56));
	//black units
	for (int i = 0; i < 8; i++)
		SDL_RenderCopy(m_Rend, t_unit, &tex_.ImageRect(288, 0, 56, 56), &tex_.ImageRect(bPawn[i].back().GetX(), bPawn[i].back().GetY(), 56, 56));
	for (int i = 0; i < 2; i++)
	{
		SDL_RenderCopy(m_Rend, t_unit, &tex_.ImageRect(57, 0, 56, 56), &tex_.ImageRect(bKnight[i].back().GetX(), bKnight[i].back().GetY(), 56, 56));
		SDL_RenderCopy(m_Rend, t_unit, &tex_.ImageRect(57 * 2, 0, 56, 56), &tex_.ImageRect(bBishop[i].back().GetX(), bBishop[i].back().GetY(), 56, 56));
		SDL_RenderCopy(m_Rend, t_unit, &tex_.ImageRect(0, 0, 56, 56), &tex_.ImageRect(bRook[i].back().GetX(), bRook[i].back().GetY(), 56, 56));
	}
	SDL_RenderCopy(m_Rend, t_unit, &tex_.ImageRect(57 * 3, 0, 56, 56), &tex_.ImageRect(bKing.back().GetX(), bKing.back().GetY(), 56, 56));
	SDL_RenderCopy(m_Rend, t_unit, &tex_.ImageRect(57 * 4, 0, 56, 56), &tex_.ImageRect(bQueen.back().GetX(), bQueen.back().GetY(), 56, 56));
	SDL_RenderPresent(m_Rend);
}
// use std:: vectors instead of class pointers for setting up positions and update
void GameEngine::UnitVectorsInit()
{
	//create std vectors for white pieces
	wPawn[0].emplace_back(Unit(Board_.GridX('A'), Board_.GridY(7))); wPawn[1].emplace_back(Unit(Board_.GridX('B'), Board_.GridY(7)));
	wPawn[2].emplace_back(Unit(Board_.GridX('C'), Board_.GridY(7))); wPawn[3].emplace_back(Unit(Board_.GridX('D'), Board_.GridY(7)));
	wPawn[4].emplace_back(Unit(Board_.GridX('E'), Board_.GridY(7))); wPawn[5].emplace_back(Unit(Board_.GridX('F'), Board_.GridY(7)));
	wPawn[6].emplace_back(Unit(Board_.GridX('G'), Board_.GridY(7))); wPawn[7].emplace_back(Unit(Board_.GridX('H'), Board_.GridY(7)));
	wKnight[0].emplace_back(Unit(Board_.GridX('B'), Board_.GridY(8))); wKnight[1].emplace_back(Unit(Board_.GridX('G'), Board_.GridY(8)));
	wBishop[0].emplace_back(Unit(Board_.GridX('C'), Board_.GridY(8))); wBishop[1].emplace_back(Unit(Board_.GridX('F'), Board_.GridY(8)));
	wRook[0].emplace_back(Unit(Board_.GridX('A'), Board_.GridY(8)));wRook[1].emplace_back(Unit(Board_.GridX('H'), Board_.GridY(8)));
	wKing.emplace_back(Unit(Board_.GridX('D'), Board_.GridY(8))); wQueen.emplace_back(Unit(Board_.GridX('E'), Board_.GridY(8)));
	//init black Pointers
	bPawn[0].emplace_back(Unit(Board_.GridX('A'), Board_.GridY(2))); bPawn[1].emplace_back(Unit(Board_.GridX('B'), Board_.GridY(2)));
	bPawn[2].emplace_back(Unit(Board_.GridX('C'), Board_.GridY(2)));bPawn[3].emplace_back(Unit(Board_.GridX('D'), Board_.GridY(2))); 
	bPawn[4].emplace_back(Unit(Board_.GridX('E'), Board_.GridY(2))); bPawn[5].emplace_back(Unit(Board_.GridX('F'), Board_.GridY(2)));
	bPawn[6].emplace_back(Unit(Board_.GridX('G'), Board_.GridY(2))); bPawn[7].emplace_back(Unit(Board_.GridX('H'), Board_.GridY(2)));
	bKnight[0].emplace_back(Unit(Board_.GridX('B'), Board_.GridY(1))); bKnight[1].emplace_back(Unit(Board_.GridX('G'), Board_.GridY(1)));
	bBishop[0].emplace_back(Unit(Board_.GridX('C'), Board_.GridY(1))); bBishop[1].emplace_back(Unit(Board_.GridX('F'), Board_.GridY(1)));
	bRook[0].emplace_back(Unit(Board_.GridX('A'), Board_.GridY(1))); bRook[1].emplace_back(Unit(Board_.GridX('H'), Board_.GridY(1)));
	bKing.emplace_back(Unit(Board_.GridX('D'), Board_.GridY(1))); bQueen.emplace_back(Unit(Board_.GridX('E'), Board_.GridY(1)));
}

void GameEngine::CreateSurfaceandTexture()
{
	
	//create board texture from surface
	t_board = SDL_CreateTextureFromSurface(m_Rend, tex_.GetboardSurface());
	t_unit = SDL_CreateTextureFromSurface(m_Rend, tex_.GetUnitSurface());
}

