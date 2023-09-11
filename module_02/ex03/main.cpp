#include <iostream>
#include <iostream>
#include <iomanip>

#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
	std::cout << std::boolalpha;

	std::cout << "Testing bsp:\n";

	std::cout << "Point inside triangle: ";
	std::cout << bsp(Point(Fixed(1), Fixed(1)), Point(Fixed(2), Fixed(1)), Point(Fixed(1), Fixed(2)), Point(Fixed(1.1f), Fixed(1.1f))) << "\n";

	std::cout << "Point on triangle: ";
	std::cout << bsp(Point(Fixed(1), Fixed(1)), Point(Fixed(2), Fixed(1)), Point(Fixed(1), Fixed(2)), Point(Fixed(1.5f), Fixed(1.5f))) << "\n";

	std::cout << "Point outside triangle: ";
	std::cout << bsp(Point(Fixed(1), Fixed(1)), Point(Fixed(2), Fixed(1)), Point(Fixed(1), Fixed(2)), Point(Fixed(2.1f), Fixed(2.1f))) << "\n";

	return 0;
}
