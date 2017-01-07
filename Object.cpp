#include "Object.hpp"
#include <SDL2pp/SDL2pp.hh>
#include "globals.hpp"

Object::Object(Vector2D newPos, Vector2D newSize)
	: pos{newPos}, size{newSize}
{}

void Object::update(int delta)
{
	pos += vel * (delta / 100.0f);
	rect = SDL2pp::Rect{ pos.x, pos.y, size.x, size.y };
}

void Object::render()
{
	gRenderer.SetDrawColor(255, 255, 255);
	gRenderer.FillRect(rect);
}

Vector2D Object::getVelocity() const { return vel; }
void Object::setVelocity(Vector2D newVel) { vel = newVel; }
void Object::push(Vector2D newAcc) { vel += newAcc; }

SDL2pp::Rect Object::getRect() const { return rect; }
