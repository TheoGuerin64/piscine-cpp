#include <iostream>

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clapTrap1;
	ClapTrap clapTrap2("ClapTrap2");
	ClapTrap clapTrap3(clapTrap2);
	ClapTrap clapTrap4;

	clapTrap4 = clapTrap2;

	clapTrap1.attack("clapTrap2");
	clapTrap2.attack("clapTrap1");
	clapTrap3.attack("clapTrap1");
	clapTrap4.attack("clapTrap1");

	clapTrap1.takeDamage(0);
	clapTrap2.takeDamage(3);
	clapTrap3.takeDamage(7);
	clapTrap4.takeDamage(11);

	clapTrap1.beRepaired(10);
	clapTrap2.beRepaired(7);
	clapTrap3.beRepaired(5);
	clapTrap4.beRepaired(2);

	return 0;
}
