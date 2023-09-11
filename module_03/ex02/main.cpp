#include <iostream>

#include "FragTrap.hpp"

int main(void)
{
	FragTrap FragTrap1;
	FragTrap FragTrap2("FragTrap2");
	FragTrap FragTrap3(FragTrap2);
	FragTrap FragTrap4;

	FragTrap4 = FragTrap2;

	FragTrap1.highFivesGuys();
	FragTrap2.highFivesGuys();
	FragTrap3.highFivesGuys();
	FragTrap4.highFivesGuys();

	return 0;
}
