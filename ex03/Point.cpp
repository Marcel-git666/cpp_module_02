
#include "Point.hpp"

// Orthodox Canonical Form
Point::Point(void) : x(0), y(0) {}
Point::Point(float x_val, float y_val) : x(x_val), y(y_val) {}
Point::Point(Point const &other) : x(other.x), y(other.y) {}
Point &Point::operator=(Point const &other) {
    (void)other;
    return *this;
}
Point::~Point(void) {}

Fixed Point::getX(void) const { return x; }
Fixed Point::getY(void) const { return y; }