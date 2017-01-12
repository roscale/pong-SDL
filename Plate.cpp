#include "Plate.hpp"
#include "globals.hpp"

const Vector2D Plate::plateSize {10, 100};

Plate::Plate(Vector2D newPos) : Object(newPos, plateSize)
{}

void Plate::update()
{
	Object::update();
	edges();
}

void Plate::edges()
{
	bool dirty = false;

	if (pos.y < 0)
	{
		pos.y = 0;
		dirty = true;
	}

	else if (pos.y > gWindow.GetHeight() - size.y)
	{
		pos.y = gWindow.GetHeight() - size.y;
		dirty = true;
	}

	if (dirty)
		calculateRect();
}

void Plate::moveUp() { vel = Vector2D{0, -movingSpeed}; }
void Plate::moveDown() { vel = Vector2D{0, movingSpeed}; }
void Plate::stopMoving() { vel = Vector2D{0, 0}; }
