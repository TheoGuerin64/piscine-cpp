#include <string>
#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called\n";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "FragTrap name constructor called\n";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called\n";
	*this = other;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	std::cout << "FragTrap assignation operator called\n";
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << _name << " gives a high five\n";
}
