#include <string>
#include <iostream>

#include "iter.hpp"

template <typename T>
void	print(T &value)
{
	std::cout << value << "\n";
}

int main(void)
{
	{
		int array[5] = {5, 6, 7, 8, 9};
		iter(array, 5, print);
	}
	{
		double array[6] = {4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
		iter(array, 6, print);
	}
	{
		std::string array[4] = {"salut", "ça", "va", "?"};
		iter(array, 4, print);
	}
	return 0;
}
