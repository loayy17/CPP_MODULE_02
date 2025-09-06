#include "Point.hpp"
Point::Point(int x, int y) : _x(x), _y(y) {}
Point::Point(const float &x, const float &y) : _x(x), _y(y) {}
Point::Point(const Point &other) : _x(other._x), _y(other._y) {}
Point &Point::operator=(const Point &other) {
    (void)other; // To avoid unused parameter warning
    return *this;
}
Point::~Point() {}
Fixed Point::getX() const {
    return _x;
}
Fixed Point::getY() const {
    return _y;
}