#include "Ball.hpp"
#include "globals.hpp"

const int Ball::radius{5};

Ball::Ball(Vector2D newPos) : Object(newPos, Vector2D{2*radius, 2*radius})
{
	vel = {-5, -0};
}

int Ball::getRadius() const { return radius; }

void Ball::reset() {
	setPosition(Vector2D{gWindow.GetWidth() / 2, gWindow.GetHeight() / 2});
	vel = {-5, -0};
}
