#include <cstring>

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::memset(_inventory, 0, sizeof(_inventory));
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::memset(_inventory, 0, sizeof(_inventory));
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			delete _inventory[i];
		for (int i = 0; i < 4; i++)
			_inventory[i] = other._inventory[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = materia;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return NULL;
}
