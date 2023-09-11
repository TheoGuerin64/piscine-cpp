#include <iostream>
#include <string>

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("Unknown") {}

Zombie::Zombie(const std::string &name) : _name(name) {}

Zombie::~Zombie(void)
{
	std::cout << _name << ": Destroyed." << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name)
{
	_name = name;
}
