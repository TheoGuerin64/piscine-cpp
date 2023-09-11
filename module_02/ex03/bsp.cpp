#include "Point.hpp"

static bool isOnLeft(const Point a, const Point b, const Point point)
{
	return ((b.getX() - a.getX()) * (point.getY() - a.getY()) -
		(b.getY() - a.getY()) * (point.getX() - a.getX())) > 0;
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	return isOnLeft(a, b, point)
		&& isOnLeft(b, c, point)
		&& isOnLeft(c, a, point);
}
