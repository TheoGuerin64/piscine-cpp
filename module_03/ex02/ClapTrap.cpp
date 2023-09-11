#include <string>
#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("nlocusso"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string const &name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap name constructor called\n";
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "ClapTrap copy constructor called\n";
	*this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap assignation operator called\n";
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

void ClapTrap::attack(std::string const &target)
{
	if (_hitPoints <= 0)
		return;
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy\n";
		return;
	}

	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage <<" points of damage!\n";
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
		return;

	if (_hitPoints - (int)amount < 0)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " is dead\n";
		return;
	}
	_hitPoints -= amount;

	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of damage\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy\n";
		return;
	}

	if (_hitPoints + amount > 10)
		_hitPoints = 10;
	else
		_hitPoints += amount;

	std::cout << "ClapTrap " << _name << " is repaired by "
		<< amount << " points\n";
	_energyPoints--;
}
