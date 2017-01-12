#include "Ball.hpp"
#include "globals.hpp"

const int Ball::d{10};

Ball::Ball(Vector2D newPos) : Object(newPos, Vector2D{d, d})
{
	vel = {-5, 0};
}

void Ball::update()
{
	Object::update();
	edges();
}

void Ball::edges()
{
	if (pos.y < 0 || pos.y > gWindow.GetHeight() - d)
	{
		setPosition(last_pos);
		vel.y *= -1;
	}

	// Debugging
	if (pos.x < 0 || pos.x > gWindow.GetWidth() - d)
	{
		vel = {-5, 0};
		setPosition(Vector2D{gWindow.GetWidth()/2, gWindow.GetHeight()/2});
	}
}
