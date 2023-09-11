#include <iostream>

#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal(void) : _type("AbstractAnimal")
{
	std::cout << "AbstractAnimal default constructor called\n";
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &other)
{
	std::cout << "AbstractAnimal copy constructor called\n";
	*this = other;
}

AbstractAnimal &AbstractAnimal::operator=(const AbstractAnimal &other)
{
	std::cout << "AbstractAnimal assignment operator called\n";
	_type = other._type;
	return *this;
}

AbstractAnimal::~AbstractAnimal()
{
	std::cout << "AbstractAnimal destructor called\n";
}

std::string const &AbstractAnimal::getType(void) const
{
	return _type;
}
