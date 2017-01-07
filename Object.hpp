#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Vector2D.hpp"

class Object
{
protected:
	Vector2D pos;
	Vector2D size;
	Vector2D vel{0, 0};
	Vector2D acc{0, 0};
	Object(Vector2D newPos, Vector2D newSize);

public:
	virtual void update();
	virtual void render();
};

#endif /* end of include guard: OBJECT_HPP */
