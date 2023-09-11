#include <iostream>

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap DiamondTrap1;
	DiamondTrap DiamondTrap2("DiamondTrap2");
	DiamondTrap DiamondTrap3(DiamondTrap2);
	DiamondTrap DiamondTrap4;

	DiamondTrap4 = DiamondTrap2;

	DiamondTrap1.attack("DiamondTrap2");
	DiamondTrap2.attack("DiamondTrap1");
	DiamondTrap3.attack("DiamondTrap1");
	DiamondTrap4.attack("DiamondTrap1");

	DiamondTrap1.whoAmI();
	DiamondTrap2.whoAmI();
	DiamondTrap3.whoAmI();
	DiamondTrap4.whoAmI();

	return 0;
}
