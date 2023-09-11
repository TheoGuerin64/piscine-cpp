#include <iostream>

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called\n";
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignment operator called\n";
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

std::string const &Brain::getIdea(int index)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Index out of range\n";
		return NULL;
	}
	return _ideas[index];
}

void Brain::setIdea(int index, std::string const &value)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Index out of range\n";
		return;
	}
	_ideas[index] = value;
}
