#ifndef PLATE_HPP
#define PLATE_HPP

#include "Object.hpp"

class Plate : public Object
{
public:
	static const Vector2D plateSize;
	
public:
	Plate(Vector2D newPos);

	void setVelocity(Vector2D newVel);
	void push(Vector2D newAcc);
};

#endif /* end of include guard: PLATE_HPP */
