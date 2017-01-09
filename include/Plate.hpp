#ifndef PLATE_HPP
#define PLATE_HPP

#include "Object.hpp"

class Plate : public Object
{
public:
	static const Vector2D plateSize;
	static const int movingSpeed = 5;

public:
	Plate(Vector2D newPos);

	virtual void update() override;
	void edges();

	void moveUp();
	void moveDown();
	void stopMoving();
};

#endif /* end of include guard: PLATE_HPP */
