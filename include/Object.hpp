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
	Vector2D vel {0, 0};
	Object(Vector2D newPos, Vector2D newSize);

public:
	virtual void update();
	virtual void render();

	SDL2pp::Rect getRect() const;
	void calculateRect();

	Vector2D getPosition() const;
	void setPosition(Vector2D newPos);

	Vector2D getVelocity() const;
	void setVelocity(Vector2D newVel);
};

#endif /* end of include guard: OBJECT_HPP */
