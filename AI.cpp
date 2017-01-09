#include "AI.hpp"
#include <SDL2pp/SDL2pp.hh>

AI::AI(Plate *plate, Ball *ball)
	: plateToControl{plate}, ballToPlay{ball}
{}

void AI::play()
{
	const SDL2pp::Rect &ballRect = ballToPlay->getRect();
	const SDL2pp::Rect &plateRect = plateToControl->getRect();

	if (ballRect.GetY() < plateRect.GetY() + plateRect.GetH()/4)
		plateToControl->moveUp();

	else if (ballRect.GetY2() > plateRect.GetY2() - plateRect.GetH()/4)
		plateToControl->moveDown();

	else plateToControl->stopMoving();
}
