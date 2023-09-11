#ifndef POINT_HPP_
#define POINT_HPP_

#include "Fixed.hpp"

class Point {
	public:
		Point(void);
		Point(const Fixed x, const Fixed y);
		Point(const Point &other);
		~Point();

		const Fixed &getX(void) const;
		const Fixed &getY(void) const;

	private:
		const Fixed _x;
		const Fixed _y;

		Point &operator=(const Point &other);
};

#endif  // POINT_HPP_
