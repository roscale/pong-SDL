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
		// Enable the AI
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

				case SDLK_a:
					playerTwoPlate->moveUp(); break;

				case SDLK_q:
					playerTwoPlate->moveDown(); break;
			}

		else if (e.type == SDL_KEYUP)
		switch (e.key.keysym.sym)
		{
			case SDLK_UP:
			case SDLK_DOWN:
				playerOnePlate->stopMoving(); break;

			case SDLK_a:
			case SDLK_q:
				playerTwoPlate->stopMoving(); break;
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
	auto processColisionWith = [&](Plate *plate)
	{
		// Push back by one frame before collision
		ball->setPosition(ball->last_pos);

		// float yVelocity = (ball->getCentroid().y - plate->getCentroid().y) * 0.3f;
		Vector2D v = ball->getCentroid() - plate->getCentroid();
		std::cout << "ball: " << ball->getCentroid() << " plate: " << plate->getCentroid() << '\n';
		std::cout << v << '\n';


		if (v.length() > 20)
		{
			v.y *= 0.3;
			ball->vel = v;
		}
		else
			ball->vel.x *= -1;
		// std::cout << yVelocity << '\n';

		//Be effective only on edges
		// yVelocity = (abs(yVelocity) > 5) ? yVelocity : ball->getVelocity().y;
		// ball->setVelocity(Vector2D{ -ball->getVelocity().x, yVelocity });

	};

	if (playerOnePlate->getRect().Intersects(ball->getRect()))
		processColisionWith(playerOnePlate.get());

	else if (playerTwoPlate->getRect().Intersects(ball->getRect()))
		processColisionWith(playerTwoPlate.get());
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
