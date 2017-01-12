#include "Object.hpp"
#include <SDL2pp/SDL2pp.hh>
#include "globals.hpp"

Object::Object(Vector2D newPos, Vector2D newSize)
	: pos{newPos}, size{newSize}
{}

void Object::update()
{
	setPosition(getPosition() + vel);
}

void Object::render()
{
	gRenderer.SetDrawColor(255, 255, 255);
	gRenderer.FillRect(rect);
}

SDL2pp::Rect Object::getRect() const { return rect; }
void Object::calculateRect() { rect = SDL2pp::Rect{ pos.x, pos.y, size.x, size.y }; }

Vector2D Object::getCentroid() const { return pos + size/2; }
Vector2D Object::getPosition() const { return pos; };
void Object::setPosition(Vector2D newPos)
{
	last_pos = pos;
	pos = newPos;
	calculateRect();
}
