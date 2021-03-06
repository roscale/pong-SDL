#ifndef PLATE_HPP
#define PLATE_HPP

#include "Object.hpp"
#include "Score.hpp"

class Plate : public Object
{
public:
	static const Vector2D plateSize;
	static const int movingSpeed = 7;

public:
	Plate(Vector2D newPos);

	Score score;

	void moveUp();
	void moveDown();
	void stopMoving();
};

#endif /* end of include guard: PLATE_HPP */
