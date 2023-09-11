#include <string>

#include "AMateria.hpp"

AMateria::AMateria(void)
	: _type("Unknown")
{}

AMateria::AMateria(std::string const &type)
	: _type(type)
{}

AMateria::AMateria(const AMateria &other)
{
	(void)other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	(void)other;
	return *this;
}

AMateria::~AMateria()
{}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

std::string const &AMateria::getType() const
{
	return _type;
}
