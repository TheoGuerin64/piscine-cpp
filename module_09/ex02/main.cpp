#include <iostream>
#include <sstream>
#include <climits>

#include "PmergeMe.hpp"

static bool isDigits(const char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

static int *parseArray(char **input, int size)
{
	int *array = new int[size];
	for (int i = 0; i < size; i++)
	{
		std::istringstream iss(input[i]);
		if (!isDigits(input[i]) || !(iss >> array[i]))
		{
			delete[] array;
			return NULL;
		}
	}
	return array;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error\n";
		return 1;
	}

	int *array = parseArray(argv + 1, argc - 1);
	if (!array)
	{
		std::cerr << "Error\n";
		return 1;
	}

	try
	{
		PmergeMe::merge(array, argc - 1);
	}
	catch (const PmergeMe::MergeFailException& e)
	{
		std::cerr << "Error\n";
		delete[] array;
		return 1;
	}

	delete[] array;
	return 0;
}
