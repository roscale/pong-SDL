#include <SDL2pp/SDL2pp.hh>
#include <SDL2/SDL_image.h>

#include "Game.hpp"
#include "globals.hpp"
#include "Timer.hpp"
#include "Vector2D.hpp"

#include <vector>

SDL sdl(SDL_INIT_VIDEO);
Window gWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
Renderer gRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
Timer gTimer;

int main()
{
	Game game;
	game.gameLoop();

	return 0;
}
