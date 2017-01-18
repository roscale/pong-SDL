#ifndef BALL_HPP
#define BALL_HPP

#include "Object.hpp"

class Ball : public Object
{
private:
	static const int radius;

public:
	Ball(Vector2D newPos);

	int getRadius() const;
	void reset();
};

#endif /* end of include guard: BALL_HPP */
