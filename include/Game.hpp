#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <memory>
#include "Object.hpp"

class Game
{
private:
	std::vector<std::unique_ptr<Object>> objects;

public:
	Game();
	void gameLoop();

	bool handleInput();
	void update(int delta);
	void collisions();
	void render();
};

#endif /* end of include guard: GAME_HPP */
