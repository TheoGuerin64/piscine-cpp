#include <iostream>

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap ScavTrap1;
	ScavTrap ScavTrap2("ScavTrap2");
	ScavTrap ScavTrap3(ScavTrap2);
	ScavTrap ScavTrap4;

	ScavTrap4 = ScavTrap2;

	ScavTrap1.attack("ScavTrap2");
	ScavTrap2.attack("ScavTrap1");
	ScavTrap3.attack("ScavTrap1");
	ScavTrap4.attack("ScavTrap1");

	ScavTrap1.guardGate();
	ScavTrap2.guardGate();
	ScavTrap3.guardGate();
	ScavTrap4.guardGate();

	return 0;
}
