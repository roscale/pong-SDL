#include "Game.hpp"
#include "globals.hpp"
#include "Plate.hpp"

Game::Game()
{
	int margin = 20;

	auto playerOnePlate = std::make_unique<Plate>( Vector2D{margin, gWindow.GetHeight()/2} );
	auto playerTwoPlate = std::make_unique<Plate>( Vector2D{gWindow.GetWidth()-(Plate::plateSize.x + margin), gWindow.GetHeight()/2} );
	objects.push_back(std::move(playerOnePlate));
	objects.push_back(std::move(playerTwoPlate));
}

void Game::gameLoop()
{
	while (true)
	{
		if (handleInput()) break;
		update();
		render();
	}
}

bool Game::handleInput()
{
	SDL_Event e;
	if (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			return true;

		else if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
			switch (e.key.keysym.sym)
			{
				case SDLK_UP:
					break;
			}
	}
	return false;
}

void Game::update()
{
	for (auto &object : objects)
		object->update();
}

void Game::render()
{
	gRenderer.SetDrawColor(0, 0, 0);
	gRenderer.Clear();

	for (auto &object : objects)
		object->render();

	gRenderer.Present();
}
