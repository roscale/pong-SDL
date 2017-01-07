#ifndef PLATE_HPP
#define PLATE_HPP

#include "Object.hpp"

class Plate : public Object
{
public:
	static const Vector2D plateSize;

public:
	Plate(Vector2D newPos);

	virtual void update(int delta) override;
	void edges();
};

#endif /* end of include guard: PLATE_HPP */
