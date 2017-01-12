#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <iostream>
// #include <SDL2pp/SDL2pp.hh>

class Vector2D
{
public:
	float x;
	float y;

	Vector2D(float vx = 0, float vy = 0);

	float length() const;
	Vector2D& normalize();
	Vector2D normalized() const;

	friend bool operator==(const Vector2D &v1, const Vector2D &v2);
	friend bool operator!=(const Vector2D &v1, const Vector2D &v2);
	friend bool operator< (const Vector2D &v1, const Vector2D &v2);
	friend bool operator<=(const Vector2D &v1, const Vector2D &v2);
	friend bool operator> (const Vector2D &v1, const Vector2D &v2);
	friend bool operator>=(const Vector2D &v1, const Vector2D &v2);

	friend Vector2D operator+(const Vector2D &v1, const Vector2D &v2);
	friend Vector2D operator-(const Vector2D &v1, const Vector2D &v2);
	friend Vector2D operator*(const Vector2D &v1, const Vector2D &v2);
	friend Vector2D operator/(const Vector2D &v1, const Vector2D &v2);
	friend Vector2D operator*(const Vector2D &v1, float n);
	friend Vector2D operator/(const Vector2D &v1, float n);

	Vector2D& operator+=(const Vector2D &v);
	Vector2D& operator-=(const Vector2D &v);
	Vector2D& operator*=(const Vector2D &v);
	Vector2D& operator/=(const Vector2D &v);
	Vector2D& operator*=(float n);
	Vector2D& operator/=(float n);

	friend std::ostream& operator<<(std::ostream &out, const Vector2D &v);

};


#endif /* end of include guard: VECTOR2D_HPP */
