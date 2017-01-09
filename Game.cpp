#include "Game.hpp"
#include "globals.hpp"
#include "Plate.hpp"
#include "Ball.hpp"

Game::Game()
{
	int plateMargin = 20;

	playerOnePlate = std::make_unique<Plate>(Vector2D{plateMargin, gWindow.GetHeight()/2});
	playerTwoPlate = std::make_unique<Plate>(Vector2D{gWindow.GetWidth()-(Plate::plateSize.x + plateMargin), gWindow.GetHeight()/2});
	ball = std::make_unique<Ball>(Vector2D{gWindow.GetWidth()/2, gWindow.GetHeight()/2});

	ai = std::make_unique<AI>(playerTwoPlate.get(), ball.get());
}

void Game::gameLoop()
{
	while (true)
	{
		if (handleInput()) break;
		ai->play();

		collisions();
		update();

		// gTimer.start();
		render();

		SDL_Delay(10);
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
					playerOnePlate->moveUp(); break;

				case SDLK_DOWN:
					playerOnePlate->moveDown(); break;
			}

		else if (e.type == SDL_KEYUP)
		switch (e.key.keysym.sym)
		{
			case SDLK_UP:
			case SDLK_DOWN:
				playerOnePlate->stopMoving(); break;
		}
	}
	return false;
}

void Game::update()
{
	playerOnePlate->update();
	playerTwoPlate->update();
	ball->update();
}

void Game::collisions()
{
	if (playerOnePlate->getRect().Intersects(ball->getRect()) ||
		 playerTwoPlate->getRect().Intersects(ball->getRect()))
	{
		// ball->setPosition(ball->getPosition() - ball->getVelocity());
		ball->setVelocity(ball->getVelocity() * Vector2D{-1, 1});
	}
}

void Game::render()
{
	gRenderer.SetDrawColor(0, 0, 0);
	gRenderer.Clear();

	playerOnePlate->render();
	playerTwoPlate->render();
	ball->render();

	gRenderer.Present();
}
