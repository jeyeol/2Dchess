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

void GameEngine::Engine()
{
	RenderTexture();
	PositionUpdate();
}
void GameEngine::InitWindowandRenderer()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)	{ std::cout << "Subsystems Initialized..." << std::endl;}
	//initialize window
	m_Window = SDL_CreateWindow("2D Chess Game!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 800, SDL_WINDOW_OPENGL);
	if (m_Window == nullptr){ std::cout << "window failed to initialized...." << std::endl;	}
	//create renderer & render error code
	m_Rend = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
	if (m_Rend == nullptr) { std::cout << "Renderer failed to initialized...." << std::endl;}
	//background color setup = white
	SDL_SetRenderDrawColor(m_Rend, 0, 0, 0, 255);
}

void GameEngine::RenderTexture()
{
	//rendering the board
	SDL_RenderCopy(m_Rend, t_board, NULL, &tex_.ImageRect(0, 0, 504, 504));
	//unit rendering
	for (int i = 0; i < 16; i++)
	{
		SDL_RenderCopy(m_Rend, t_unit, &tex_.WhiteUnit(i), &tex_.ImageRect(wUnits[i].GetX(), wUnits[i].GetY(), 56, 56)); //white
		SDL_RenderCopy(m_Rend, t_unit, &tex_.BlackUnit(i), &tex_.ImageRect(bUnits[i].GetX(), bUnits[i].GetY(), 56, 56)); //black
	}
	SDL_RenderPresent(m_Rend);
}
// use std:: vectors instead of class pointers for setting up positions and update
void GameEngine::UnitVectorsInit()
{
	char letter[8] = { 'A','B', 'C', 'D', 'E', 'F', 'G', 'H' };
	for (int i=0; i<8; i++)
	wUnits.emplace_back(Unit(Board_.GridX(letter[i]), Board_.GridY(7), Unit_.WHITE, Unit_.PAWN));//white pawns
	wUnits.emplace_back(Unit(Board_.GridX('B'), Board_.GridY(8), Unit_.WHITE, Unit_.KNIGHT));//white knight 1
	wUnits.emplace_back(Unit(Board_.GridX('G'), Board_.GridY(8), Unit_.WHITE, Unit_.KNIGHT));//white knight 2
	wUnits.emplace_back(Unit(Board_.GridX('C'), Board_.GridY(8), Unit_.WHITE, Unit_.BISHOP));//white bishop 1
	wUnits.emplace_back(Unit(Board_.GridX('F'), Board_.GridY(8), Unit_.WHITE, Unit_.BISHOP));//white bishop 2
	wUnits.emplace_back(Unit(Board_.GridX('A'), Board_.GridY(8), Unit_.WHITE, Unit_.ROOK));// white rook
	wUnits.emplace_back(Unit(Board_.GridX('H'), Board_.GridY(8), Unit_.WHITE, Unit_.ROOK));// white rook2
	wUnits.emplace_back(Unit(Board_.GridX('D'), Board_.GridY(8), Unit_.WHITE, Unit_.KING));// white king
	wUnits.emplace_back(Unit(Board_.GridX('E'), Board_.GridY(8), Unit_.WHITE, Unit_.QUEEN)); // white queen

	for (int i = 0; i < 8; i++)
	bUnits.emplace_back(Unit(Board_.GridX(letter[i]), Board_.GridY(2), Unit_.BLACK, Unit_.PAWN)); //black pawns
	bUnits.emplace_back(Unit(Board_.GridX('B'), Board_.GridY(1), Unit_.BLACK, Unit_.KNIGHT)); //black knight1
	bUnits.emplace_back(Unit(Board_.GridX('G'), Board_.GridY(1), Unit_.BLACK, Unit_.KNIGHT)); //black knight2																							  //init black Pointers
	bUnits.emplace_back(Unit(Board_.GridX('C'), Board_.GridY(1), Unit_.BLACK, Unit_.BISHOP)); //black bishop1
	bUnits.emplace_back(Unit(Board_.GridX('F'), Board_.GridY(1), Unit_.BLACK, Unit_.BISHOP)); //black bishop2
	bUnits.emplace_back(Unit(Board_.GridX('A'), Board_.GridY(1), Unit_.BLACK, Unit_.ROOK)); //black rook1
	bUnits.emplace_back(Unit(Board_.GridX('H'), Board_.GridY(1), Unit_.BLACK, Unit_.ROOK)); //black rook2
	bUnits.emplace_back(Unit(Board_.GridX('D'), Board_.GridY(1), Unit_.BLACK, Unit_.KING)); //black king
	bUnits.emplace_back(Unit(Board_.GridX('E'), Board_.GridY(1), Unit_.BLACK, Unit_.QUEEN)); //black Queen
	
}

void GameEngine::CreateSurfaceandTexture()
{	
	//create board texture from surface
	t_board = SDL_CreateTextureFromSurface(m_Rend, tex_.GetboardSurface());
	t_unit = SDL_CreateTextureFromSurface(m_Rend, tex_.GetUnitSurface());
}
//update piece information & cover the movement logic
void GameEngine::PositionUpdate()
{	for (int i=0; i<16; i++)
	Input_.MouseInput(wUnits, i);
}
