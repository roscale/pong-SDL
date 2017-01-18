#include <SDL2pp/SDL2pp.hh>
#include <SDL2/SDL_ttf.h>

#include "Game.hpp"
#include "globals.hpp"
#include "Timer.hpp"
#include "Vector2D.hpp"

#include <vector>

SDL sdl(SDL_INIT_VIDEO);
SDLTTF sdl_ttf;
Window gWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
Vector2D windowCenter{gWindow.GetWidth()/2, gWindow.GetHeight()/2};
Renderer gRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
Timer gTimer;
Font scoreFont("../resources/square.ttf", 42, 0);

int main()
{
	Game game;
	game.gameLoop();

	return 0;
}
