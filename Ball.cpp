#include "Ball.hpp"
#include "globals.hpp"

const int Ball::r{10};

Ball::Ball(Vector2D newPos) : Object(newPos, Vector2D{r, r})
{
	vel = {-20, 10};
}

void Ball::update(int delta)
{
	Object::update(delta);
	edges();
}

void Ball::edges()
{
	if (pos.y < 0 || pos.y > gWindow.GetHeight() - r)
		vel.y *= -1;

	// Debugging
	if (pos.x < 0 || pos.x > gWindow.GetWidth() - r)
		vel.x *= -1;
}