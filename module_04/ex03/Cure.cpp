#include <iostream>

#include "Cure.hpp"

Cure::Cure(void)
	: AMateria("cure")
{}

Cure::Cure(const Cure &other)
	: AMateria("cure")
{
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	AMateria::operator=(other);
	return *this;
}

Cure::~Cure()
{}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
