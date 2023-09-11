#include <iostream>

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void) : AbstractAnimal()
{
	std::cout << "Cat default constructor called\n";
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : AbstractAnimal()
{
	std::cout << "Cat copy constructor called\n";
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called\n";
	AbstractAnimal::operator=(other);
	delete _brain;
	_brain = new Brain(*other._brain);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete _brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!\n";
}

Brain const *Cat::getBrain(void) const
{
	return _brain;
}

std::string const &Cat::getIdea(int index) const
{
	return _brain->getIdea(index);
}

void Cat::setIdea(int index, std::string const &value)
{
	_brain->setIdea(index, value);
}
