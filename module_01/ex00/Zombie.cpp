#include <iostream>
#include <string>

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("Unknown") {}

Zombie::Zombie(const std::string &name) : _name(name) {}

Zombie::~Zombie()
{
	std::cout << _name << ": Destroyed.\n";
}

void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
