#include <iostream>

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error\n";
		return 1;
	}

	try
	{
		std::cout << RPN::resolve(argv[1]) << "\n";
	}
	catch (RPN::CalculNotValidException &e)
	{
		std::cout << "Error\n";
	}
	return 0;
}
