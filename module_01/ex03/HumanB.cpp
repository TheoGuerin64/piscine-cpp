#include <cstddef>
#include <iostream>
#include <string>

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL) {}

void HumanB::attack(void) const
{
	std::cout << _name << " attacks with their ";
	if (_weapon)
		std::cout << _weapon->getType();
	else
		std::cout << "fists";
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
