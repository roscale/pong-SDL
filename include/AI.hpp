#ifndef AI_HPP
#define AI_HPP

#include "Plate.hpp"
#include "Ball.hpp"

class AI
{
private:
	Plate *plateToControl;
	Ball *ballToPlay;

public:
	AI(Plate *plate, Ball *ball);
	void play();
};

#endif /* end of include guard: AI_HPP */
