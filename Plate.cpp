#include "Plate.hpp"

const Vector2D Plate::plateSize {10, 100};

Plate::Plate(Vector2D newPos) : Object(newPos, plateSize)
{}

void Plate::setVelocity(Vector2D newVel) { vel = newVel; }
void Plate::push(Vector2D newAcc) { acc = newAcc; }
