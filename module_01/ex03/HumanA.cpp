#include <iostream>
#include <string>

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, const Weapon &Weapon)
	: _name(name), _weapon(Weapon) {}

void HumanA::attack(void) const
{
	std::cout << _name << " attacks with their " << _weapon.getType();
	std::cout << std::endl;
}
