#include "Fixed.hpp"

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other)
{
	std::cout << "Assignation operator should not be called" << std::endl;
	(void)other;
	return *this;
}

Point::~Point() {}


const Fixed &Point::getX(void) const
{
	return _x;
}

const Fixed &Point::getY(void) const
{
	return _y;
}
