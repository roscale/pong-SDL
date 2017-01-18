#include "Game.hpp"
#include "globals.hpp"
#include "Plate.hpp"
#include "Ball.hpp"

Game::Game() : scoreTexture{new SDL2pp::Texture{gRenderer, scoreFont.RenderUTF8_Blended("0 | 0", SDL_Color{150, 150, 150})}}
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

		update();
		collisions();

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
	// Lambda expressions used do dynamically resolve colisions
	auto plateHitsEdge = [&](Plate *plate)
	{
		if (plate->getPosition().y < 0 || plate->getPosition().y > gWindow.GetHeight() - plate->size.y)
			plate->setPosition(plate->last_pos);
	};

    auto ballWentLeft = [&]() {
        return (ball->getPosition().x < 0);
    };
    auto ballWentRight = [&]() {
        return (ball->getPosition().x > gWindow.GetWidth() - 2*ball->getRadius());
    };

	auto ballHitsEdge = [&]()
	{
		if (ball->getPosition().y < 0 || ball->getPosition().y > gWindow.GetHeight() - 2*ball->getRadius())
		{
			ball->setPosition(ball->last_pos);
			ball->vel.y *= -1;
		}

        // Debugging
//        if (ballWentLeft() || ballWentRight())
//        {
//            // ball->setPosition(ball->last_pos);
//            // ball->vel.x *= -1;
//            // Reset ball to the center
//            ball->vel = {-5, 0};
//            ball->setPosition(Vector2D{gWindow.GetWidth()/2, gWindow.GetHeight()/2});
//        }
    };

	auto ballColidesWith = [&](Plate *plate)
	{
		if (plate->getRect().Intersects(ball->getRect())) {
			// Push back by one frame before collision
			ball->setPosition(ball->last_pos);

			Vector2D force = ball->getCentroid() - plate->getCentroid();
			if (force.length() > 20)
			{
				// Get angles more to the center
				force.y *= 0.3;
				// Reduce the force
				force *= 0.7;
				ball->vel = force;
			}
			else
				ball->vel.x *= -1;
		}
	};

	auto updateScore = [&]() {
		std::string str_playerOneScore = std::to_string(playerOnePlate->score.get());
		std::string str_playerTwoScore = std::to_string(playerTwoPlate->score.get());

		SDL2pp::Surface tempScoreSurface = scoreFont.RenderUTF8_Blended(str_playerOneScore + " | " + str_playerTwoScore, SDL_Color{150, 150, 150});
		scoreTexture.reset(new SDL2pp::Texture(gRenderer, tempScoreSurface));
		// std::cout << "UPDATING\n";
	};

	// Bound checking
	plateHitsEdge(playerOnePlate.get());
	plateHitsEdge(playerTwoPlate.get());

	ballHitsEdge();
	if (ballWentLeft() || ballWentRight())
	{
		if (ballWentLeft())
			playerTwoPlate->score.increment();
		else if (ballWentRight())
			playerOnePlate->score.increment();

		// std::cout << "BALL HITS LEFT/RIGHT\n";
		updateScore();
		ball->reset();
	}

	ballColidesWith(playerOnePlate.get());
	ballColidesWith(playerTwoPlate.get());
}

void Game::render()
{
	gRenderer.SetDrawColor(0, 0, 0);
	gRenderer.Clear();

	Vector2D scoreTextureSize{scoreTexture->GetSize()};
	Vector2D scoreRenderPos{windowCenter - scoreTextureSize/2};
	gRenderer.Copy(*scoreTexture, NullOpt, SDL2pp::Rect{scoreRenderPos.x, scoreRenderPos.y,
	                                                    scoreTexture->GetWidth(), scoreTexture->GetHeight()});

	playerOnePlate->render();
	playerTwoPlate->render();
	ball->render();

	gRenderer.Present();
}
