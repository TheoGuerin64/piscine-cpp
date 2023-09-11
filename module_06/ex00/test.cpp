#include <string>
#include <iostream>

#include "ScalarConverter.hpp"

#define BLUE_BOLD "\033[1;34m"
#define RESET "\033[0m"

#define TESTS 16

static std::string tests[TESTS] = {
	"0",
	"*",
	"42",
	"42.42",
	"42.42f",
	"nan",
	"nanf",
	"inff",
	"-inff",
	"inf",
	"-inf",
	"2147483647",
	"-2147483648",
	"2147483648",
	"-2147483649",
	"salut"
};

static void testConvert(std::string const &str)
{
	std::cout << BLUE_BOLD"./convert " << str << RESET"\n";
	ScalarConverter::convert(str);
}

int main(void)
{
	for (size_t i = 0; i < TESTS; i++)
	{
		testConvert(tests[i]);
		if (i < TESTS - 1)
			std::cout << "\n";
	}
	return 0;
}
