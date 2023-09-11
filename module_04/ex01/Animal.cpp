#include <iostream>

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called\n";
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignment operator called\n";
	_type = other._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

void Animal::makeSound(void) const
{
	std::cout << "Animal!\n";
}

std::string const &Animal::getType(void) const
{
	return _type;
}
