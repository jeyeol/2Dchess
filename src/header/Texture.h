#pragma once
#include "dep/include/SDL2/SDL.h"
#include "dep/include/SDL2/SDL_image.h"
#include "dep/include/glm/glm/glm.hpp"
#include <iostream>

class Texture
{
public:
	Texture();
	~Texture();
	void Init();
	void LoadImage();
	void FreeSurface(SDL_Surface* surf);
	void DeleteTexture(SDL_Texture* tex);
	SDL_Rect ImageRect(int x, int y, int h, int w);
	SDL_Texture* CreateTexture(SDL_Renderer* Rend, SDL_Texture* texture, SDL_Surface* sourceSurface);
	SDL_Surface* GetboardSurface() { return s_board; };
	SDL_Surface* GetUnitSurface() { return s_unit; };
	SDL_Surface* GetTurnUI() { return s_TurnUI; };
	SDL_Rect WhiteUnit(int i);
	SDL_Rect BlackUnit(int i);
	
private:
	SDL_Rect Rect;
	SDL_Surface* s_board;
	SDL_Surface* s_unit;
	SDL_Surface* s_TurnUI=nullptr;
};