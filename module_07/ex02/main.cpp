#include <iostream>
#include <stdlib.h>

#include "Array.hpp"

int main(void)
{
	Array<int> a(10);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;

	std::cout << "----------------" << std::endl;

	Array<int> b(a);
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
	
	std::cout << "----------------" << std::endl;

	Array<int> c;
	c = b;
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << std::endl;

	std::cout << "----------------" << std::endl;

	Array<int> d(5);
	d = c;
	for (unsigned int i = 0; i < d.size(); i++)
		std::cout << d[i] << std::endl;

	std::cout << "----------------" << std::endl;

	for (unsigned int i = 0; i < d.size(); i++)
		a[i] = i * 2;

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
}
