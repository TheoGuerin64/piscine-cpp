#include <iostream>

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called\n";
	_type = "Dog";
}

Dog::Dog(const Dog &other) : Animal()
{
	std::cout << "Dog copy constructor called\n";
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called\n";
	Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!\n";
}
