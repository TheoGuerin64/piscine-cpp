#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat default constructor called\n";
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat assignment operator called\n";
	WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meow !\n";
}
