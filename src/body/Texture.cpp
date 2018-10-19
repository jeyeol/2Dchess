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
	//print error message if textures fail to load
	if (s_board == nullptr) { std::cout << "board texture files failed to load"; };
	if (s_unit == nullptr) { std::cout << "unit texture file failed to load"; };
}
//imageRect method
SDL_Rect Texture::ImageRect(int x, int y, int h, int w)
{
	Rect.x = x;	Rect.y = y; Rect.h = h; Rect.w = w;
	return Rect;
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