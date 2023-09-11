#include <string>

#include "Weapon.hpp"

Weapon::Weapon() : _type("Unknown") {}

Weapon::Weapon(const std::string& name) : _type(name) {}

const std::string& Weapon::getType(void) const
{
	return _type;
}

void Weapon::setType(const std::string& type)
{
	_type = type;
}
