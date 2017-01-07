#include "Plate.hpp"
#include "globals.hpp"

const Vector2D Plate::plateSize {10, 100};

Plate::Plate(Vector2D newPos) : Object(newPos, plateSize)
{}

void Plate::update(int delta)
{
	Object::update(delta);
	edges();
}

void Plate::edges()
{
	if (pos.y < 0)
		pos.y = 0;

	else if (pos.y > gWindow.GetHeight() - size.y)
		pos.y = gWindow.GetHeight() - size.y;
}
