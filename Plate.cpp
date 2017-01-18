#include "Plate.hpp"
#include "globals.hpp"

const Vector2D Plate::plateSize {10, 100};

Plate::Plate(Vector2D newPos) : Object(newPos, plateSize), score{}
{}

void Plate::moveUp() { vel = Vector2D{0, -movingSpeed}; }
void Plate::moveDown() { vel = Vector2D{0, movingSpeed}; }
void Plate::stopMoving() { vel = Vector2D{0, 0}; }
