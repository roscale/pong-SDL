#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Vector2D.hpp"
#include <SDL2pp/SDL2pp.hh>

class Object
{
protected:
	Vector2D pos;
	Vector2D size;
	SDL2pp::Rect rect {pos.x, pos.y, size.x, size.y};
	Object(Vector2D newPos, Vector2D newSize);
	void calculateRect();

public:
	Vector2D vel {0, 0};
	Vector2D last_pos;

	virtual void update();
	virtual void render();

	SDL2pp::Rect getRect() const;

	Vector2D getPosition() const;
	void setPosition(Vector2D newPos);
	void push(Vector2D force);

	Vector2D getCentroid() const;
};

#endif /* end of include guard: OBJECT_HPP */
