#include "pch.h"
#include "src/header/GameEngine.h"


GameEngine::GameEngine() {
  InitWindowandRenderer();
  UnitVectorsInit();
  CreateSurfaceandTexture();
  SumofPieces(wUnits, bUnits);
}

GameEngine::~GameEngine() {
  tex_.DeleteTexture(t_unit);
  tex_.DeleteTexture(t_board);
  SDL_DestroyRenderer(m_Rend);
  SDL_DestroyWindow(m_Window);
}

void GameEngine::Engine() {
  RenderTexture();
  PositionUpdate();
}
void GameEngine::InitWindowandRenderer() {
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "Subsystems Initialized..." << std::endl;
  }
  // initialize window
  m_Window =
      SDL_CreateWindow("2D Chess Game!", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_OPENGL);
  if (m_Window == nullptr) {
    std::cout << "window failed to initialized...." << std::endl;
  }
  // create renderer & render error code
  m_Rend = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
  if (m_Rend == nullptr) {
    std::cout << "Renderer failed to initialized...." << std::endl;
  }
  // background color setup = white
  SDL_SetRenderDrawColor(m_Rend, 0, 0, 0, 255);
}

void GameEngine::RenderTexture() {
  // rendering the board
  SDL_RenderCopy(m_Rend, t_board, NULL, &tex_.ImageRect(0, 0, 504, 504));
  // render turn UI
  if (Input_.WhiteTurn)
    SDL_RenderCopy(m_Rend, t_UItexture, &tex_.ImageRect(0, 0, 350, 280),
                   &tex_.ImageRect(0, 504, 75, 75));
  if (!Input_.WhiteTurn)
    SDL_RenderCopy(m_Rend, t_UItexture, &tex_.ImageRect(280, 0, 350, 280),
                   &tex_.ImageRect(0, 504, 75, 75));
  // unit rendering
  for (int i = 0; i < 16; i++) {
    SDL_RenderCopy(m_Rend, t_unit, &tex_.WhiteUnit(i),
                   &tex_.ImageRect(Board_.PixelCood(wUnits[i].Getgrid()).x,
                                   Board_.PixelCood(wUnits[i].Getgrid()).y, 56,
                                   56));  // white
    SDL_RenderCopy(m_Rend, t_unit, &tex_.BlackUnit(i),
                   &tex_.ImageRect(Board_.PixelCood(bUnits[i].Getgrid()).x,
                                   Board_.PixelCood(bUnits[i].Getgrid()).y, 56,
                                   56));  // black
  }
  SDL_RenderPresent(m_Rend);
}
// use std:: vectors instead of class pointers for setting up positions and
// update
void GameEngine::UnitVectorsInit() {
  for (int i = 1; i < 9; i++)
    wUnits.emplace_back(48 + i, Unit::WHITE, Unit::PAWN, Unit::LIVE);  // white pawns
  wUnits.emplace_back(58, Unit::WHITE, Unit::KNIGHT, Unit::LIVE);  // white knight 1
  wUnits.emplace_back(63, Unit::WHITE, Unit::KNIGHT, Unit::LIVE);  // white knight 2
  wUnits.emplace_back(59, Unit::WHITE, Unit::BISHOP, Unit::LIVE);  // white bishop 1
  wUnits.emplace_back(62, Unit::WHITE, Unit::BISHOP, Unit::LIVE);  // white bishop 2
  wUnits.emplace_back(57, Unit::WHITE, Unit::ROOK, Unit::LIVE);   // white rook
  wUnits.emplace_back(64, Unit::WHITE, Unit::ROOK, Unit::LIVE);   // white rook2
  wUnits.emplace_back(61, Unit::WHITE, Unit::KING, Unit::LIVE);   // white king
  wUnits.emplace_back(60, Unit::WHITE, Unit::QUEEN, Unit::LIVE);  // white queen

  for (int i = 1; i < 9; i++)
    bUnits.emplace_back(8 + i, Unit_.BLACK, Unit_.PAWN, Unit::LIVE);  // black pawns
  bUnits.emplace_back(2, Unit_.BLACK, Unit_.KNIGHT, Unit::LIVE);  // black knight1
  bUnits.emplace_back(7, Unit_.BLACK, Unit_.KNIGHT, Unit::LIVE);  // black knight2
  bUnits.emplace_back(3, Unit_.BLACK, Unit_.BISHOP, Unit::LIVE);  // black bishop1
  bUnits.emplace_back(6, Unit_.BLACK, Unit_.BISHOP, Unit::LIVE); // black bishop2
  bUnits.emplace_back(1, Unit_.BLACK, Unit_.ROOK, Unit::LIVE);  // black rook1
  bUnits.emplace_back(8, Unit_.BLACK, Unit_.ROOK, Unit::LIVE);  // black rook2
  bUnits.emplace_back(5, Unit_.BLACK, Unit_.KING, Unit::LIVE);  // black king
  bUnits.emplace_back(4, Unit_.BLACK, Unit_.QUEEN, Unit::LIVE);  // black Queen
}

void GameEngine::CreateSurfaceandTexture() {
  // create board texture from surface
  t_board = SDL_CreateTextureFromSurface(m_Rend, tex_.GetboardSurface());
  t_unit = SDL_CreateTextureFromSurface(m_Rend, tex_.GetUnitSurface());
  t_UItexture = SDL_CreateTextureFromSurface(m_Rend, tex_.GetTurnUI());
}
// update piece information & cover the movement logic
void GameEngine::PositionUpdate() {
  if (Input_.WhiteTurn) {
    Input_.MouseInput(wUnits, wholeUnits);
  };
  if (!Input_.WhiteTurn) {
    Input_.MouseInput(bUnits, wholeUnits);
  };
};

std::vector<Unit*> GameEngine::SumofPieces(std::vector<Unit>& Vec1,
                                           std::vector<Unit>& Vec2) {
  for (auto& wPiece : Vec1) wholeUnits.push_back(&wPiece);
  for (auto& bPiece : Vec2) wholeUnits.push_back(&bPiece);
  return wholeUnits;
}
