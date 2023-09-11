#include <string>
#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	: ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap default constructor called\n";
	ClapTrap::_name = "nlocusso_clap_name";
	_name = "nlocusso";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string const &name)
	: ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap name constructor called\n";
	ClapTrap::_name = name + "_clap_name";
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap copy constructor called\n";
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "DiamondTrap assignation operator called\n";
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap " << _name << " is actually ClapTrap "
		<< ClapTrap::_name << std::endl;
}
