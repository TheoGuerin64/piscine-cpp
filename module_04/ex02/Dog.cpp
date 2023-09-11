#include <iostream>

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void) : AbstractAnimal()
{
	std::cout << "Dog default constructor called\n";
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : AbstractAnimal()
{
	std::cout << "Dog copy constructor called\n";
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called\n";
	AbstractAnimal::operator=(other);
	delete _brain;
	_brain = new Brain(*other._brain);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete _brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!\n";
}

Brain const *Dog::getBrain(void) const
{
	return _brain;
}

std::string const &Dog::getIdea(int index) const
{
	return _brain->getIdea(index);
}

void Dog::setIdea(int index, std::string const &value)
{
	_brain->setIdea(index, value);
}
