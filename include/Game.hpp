#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <memory>
#include "globals.hpp"
#include "Object.hpp"
#include "Plate.hpp"
#include "Ball.hpp"
#include "AI.hpp"

class Game
{
private:
	std::unique_ptr<Plate> playerOnePlate;
	std::unique_ptr<Plate> playerTwoPlate;
	std::unique_ptr<Ball> ball;
	std::unique_ptr<AI> ai;

	std::unique_ptr<SDL2pp::Texture> scoreTexture;

public:
	Game();
	void gameLoop();

	bool handleInput();
	void update();
	void collisions();
	void render();
};

#endif /* end of include guard: GAME_HPP */
