#include "Game.hpp"
#include "globals.hpp"
#include "Plate.hpp"
#include "Ball.hpp"

Game::Game()
{
	int margin = 20;

	auto playerOnePlate = std::make_unique<Plate>(Vector2D{margin, gWindow.GetHeight()/2});
	auto playerTwoPlate = std::make_unique<Plate>(Vector2D{gWindow.GetWidth()-(Plate::plateSize.x + margin), gWindow.GetHeight()/2});
	auto ball = std::make_unique<Ball>(Vector2D{gWindow.GetWidth()/2, gWindow.GetHeight()/2});
	objects.push_back(std::move(playerOnePlate));
	objects.push_back(std::move(playerTwoPlate));
	objects.push_back(std::move(ball));

	gTimer.start();
}

void Game::gameLoop()
{
	while (true)
	{
		if (handleInput()) break;

		int delta = gTimer.get_ticks();

		// update(delta);
		collisions();
		update(delta);
		gTimer.start();
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
					objects[0]->setVelocity(Vector2D{0, -30}); break;

				case SDLK_DOWN:
					objects[0]->setVelocity(Vector2D{0, 30}); break;
			}

		else if (e.type == SDL_KEYUP)
		switch (e.key.keysym.sym)
		{
			case SDLK_UP:
			case SDLK_DOWN:
				objects[0]->setVelocity(Vector2D{0, 0}); break;
		}
	}
	return false;
}

void Game::update(int delta)
{
	for (auto &object : objects)
		object->update(delta);
}

void Game::collisions()
{
	auto &ball = objects[2];
	if (objects[0]->getRect().Intersects(ball->getRect()) ||
		 objects[1]->getRect().Intersects(ball->getRect()))
	{
		 ball->setVelocity(ball->getVelocity() * Vector2D{-1, 1});
	}
}

void Game::render()
{
	gRenderer.SetDrawColor(0, 0, 0);
	gRenderer.Clear();

	for (auto &object : objects)
		object->render();

	gRenderer.Present();
}
