#include "pch.h"
#include "src/header/Texture.h"


Texture::Texture()
{
	LoadImage();
}


Texture::~Texture()
{
	//free surfaces
	SDL_FreeSurface(s_board);
	SDL_FreeSurface(s_unit);
}

void Texture::LoadImage()
{
	const std::string path = "rsc\\";
	int imageflag = IMG_INIT_PNG;
	if (!(IMG_Init(imageflag) & imageflag))printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	//create surface
	s_board = IMG_Load((path + "board.png").c_str());
	s_unit = IMG_Load((path + "figures.png").c_str());
	s_TurnUI = IMG_Load((path + "chessArt.jpg").c_str());
	//print error message if textures fail to load
	if (s_board == nullptr) { std::cout << "board texture files failed to load"; };
	if (s_unit == nullptr) { std::cout << "unit texture file failed to load"; };
	if (s_TurnUI == nullptr) { std::cout << "TurnUI file failed to load"; };
}
//imageRect method draw piece for units applied for both color
SDL_Rect Texture::ImageRect(int x, int y, int h, int w)
{
	Rect.x = x;	Rect.y = y; Rect.h = h; Rect.w = w;
	return Rect;
}
//assign unit image location of the units for White
SDL_Rect Texture::WhiteUnit(int i)
{	
	if (i >= 0 && i <8)  { Rect.x = 288, Rect.y = 58, Rect.h = 56, Rect.w = 56; return Rect; }
	if (i == 8 or i == 9) { Rect.x = 57, Rect.y = 58, Rect.h = 56, Rect.w = 56; return Rect; }// case for kight
	if (i == 10 or i == 11) { Rect.x = 114, Rect.y = 58, Rect.h = 56, Rect.w = 56; return Rect; }// case for bishop
	if (i == 12 or i == 13) { Rect.x = 0, Rect.y = 58, Rect.h = 56, Rect.w = 56; return Rect; }
	if (i== 14) { Rect.x = 57*3, Rect.y = 58, Rect.h = 56, Rect.w = 56; return Rect; }
	if (i == 15) { Rect.x = 57 *4, Rect.y = 58, Rect.h = 56, Rect.w = 56; return Rect; }
}
//assign unit image location of the units for black
SDL_Rect Texture::BlackUnit(int i)
{
	if (i >= 0 && i < 8) { Rect.x = 288, Rect.y = 0, Rect.h = 56, Rect.w = 56; return Rect; } // case for pawns
	if (i == 8 or i == 9) { Rect.x = 57, Rect.y = 0, Rect.h = 56, Rect.w = 56; return Rect; }// case for kights
	if (i == 10 or i == 11) { Rect.x = 114, Rect.y = 0, Rect.h = 56, Rect.w = 56; return Rect; }// case for bishops
	if (i == 12 or i == 13) { Rect.x = 0, Rect.y = 0, Rect.h = 56, Rect.w = 56; return Rect; } // case for Rook
	if (i == 14) { Rect.x = 57 * 3, Rect.y = 0, Rect.h = 56, Rect.w = 56; return Rect; } // case for king
	if (i == 15) { Rect.x = 57 * 4, Rect.y = 0, Rect.h = 56, Rect.w = 56; return Rect; } // case for queen
}
//method of assigning texture from surface
SDL_Texture* Texture::CreateTexture(SDL_Renderer* Rend, SDL_Texture* texture, SDL_Surface* sourceSurface)
{
	texture = SDL_CreateTextureFromSurface(Rend, sourceSurface);
	return texture;
}

void Texture::FreeSurface(SDL_Surface* surf)
{
	SDL_FreeSurface(surf);
}

void Texture::DeleteTexture(SDL_Texture* tex)
{
	SDL_DestroyTexture(tex);
}