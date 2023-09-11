#include <string>
#include <iostream>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called\n";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called\n";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called\n";
	*this = other;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "ScavTrap assignation operator called\n";
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::attack(std::string const &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is dead\n";
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is out of energy\n";
		return;
	}

	std::cout << "ScavTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage <<" points of damage!\n";
	_energyPoints--;
}

void ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
}
