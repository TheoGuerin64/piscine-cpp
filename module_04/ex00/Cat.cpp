#include <iostream>

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called\n";
	_type = "Cat";
}

Cat::Cat(const Cat &other) : Animal()
{
	std::cout << "Cat copy constructor called\n";
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called\n";
	Animal::operator=(other);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!\n";
}
