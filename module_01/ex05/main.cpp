#include <iostream>

#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "debug:\n";
	harl.complain("debug");
	harl.debug();
	std::cout << "\n";

	std::cout << "info:\n";
	harl.complain("info");
	harl.info();
	std::cout << "\n";

	std::cout << "warning:\n";
	harl.complain("warning");
	harl.warning();
	std::cout << "\n";

	std::cout << "error:\n";
	harl.complain("error");
	harl.error();
	std::cout << "\n";

	std::cout << "wrong complain:\n";
	harl.complain("wrong");

	return (0);
}
