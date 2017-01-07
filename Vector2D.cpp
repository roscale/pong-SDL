#include "Vector2D.hpp"

Vector2D::Vector2D(float vx, float vy) : x{vx}, y{vy}
{}

bool operator==(const Vector2D &v1, const Vector2D &v2) { return (v1.x == v2.x) && (v1.y == v2.y); }
bool operator!=(const Vector2D &v1, const Vector2D &v2) { return !(v1 == v2); }
bool operator< (const Vector2D &v1, const Vector2D &v2) { return (v1.x  < v2.x) && (v1.y  < v2.y); }
bool operator> (const Vector2D &v1, const Vector2D &v2) { return (v1.x  > v2.x) && (v1.y  > v2.y); }
bool operator<=(const Vector2D &v1, const Vector2D &v2) { return !(v1 > v2); }
bool operator>=(const Vector2D &v1, const Vector2D &v2) { return !(v1 < v2); }

Vector2D operator+(const Vector2D &v1, const Vector2D &v2) { return Vector2D(v1.x + v2.x, v1.y + v2.y); }
Vector2D operator-(const Vector2D &v1, const Vector2D &v2) { return Vector2D(v1.x - v2.x, v1.y - v2.y); }
Vector2D operator*(const Vector2D &v1, const Vector2D &v2) { return Vector2D(v1.x * v2.x, v1.y * v2.y); }
Vector2D operator/(const Vector2D &v1, const Vector2D &v2) { return Vector2D(v1.x / v2.x, v1.y / v2.y); }
Vector2D operator*(const Vector2D &v1, float n) { return Vector2D(v1.x * n, v1.y * n); }
Vector2D operator/(const Vector2D &v1, float n) { return Vector2D(v1.x / n, v1.y / n); }

Vector2D& Vector2D::operator+=(const Vector2D &v) { x += v.x; y += v.y; return *this; }
Vector2D& Vector2D::operator-=(const Vector2D &v) { x -= v.x; y -= v.y; return *this; }
Vector2D& Vector2D::operator*=(const Vector2D &v) { x *= v.x; y *= v.y; return *this; }
Vector2D& Vector2D::operator/=(const Vector2D &v) { x /= v.x; y /= v.y; return *this; }
Vector2D& Vector2D::operator*=(float n) { x *= n; y *= n; return *this; }
Vector2D& Vector2D::operator/=(float n) { x /= n; y /= n; return *this; }

std::ostream& operator<<(std::ostream &out, const Vector2D &v)
{ std::cout << "Vector2D(" << v.x << ", " << v.y << ")"; return out; }
