#include "Object.hpp"
#include <SDL2pp/SDL2pp.hh>
#include "globals.hpp"

Object::Object(Vector2D newPos, Vector2D newSize)
	: pos{newPos}, size{newSize}
{}

void Object::update()
{
	vel += acc;
	pos += vel;
}

void Object::render()
{
	gRenderer.SetDrawColor(255, 255, 255);
	gRenderer.FillRect(Rect{ pos.x, pos.y, size.x, size.y });
}
