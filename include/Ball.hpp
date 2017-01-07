#ifndef BALL_HPP
#define BALL_HPP

#include "Object.hpp"

class Ball : public Object
{
private:
	static const int r;

public:
	Ball(Vector2D newPos);

	virtual void update() override;
	void edges();
};

#endif /* end of include guard: BALL_HPP */
