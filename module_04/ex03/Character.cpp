#include <cstring>

#include "Character.hpp"

Character::Character(void)
	: _name("Unknown"), _onFloorSize(0)
{
	std::memset(_inventory, 0, sizeof(_inventory));
}

Character::Character(const std::string &name)
	: _name(name), _onFloorSize(0)
{
	std::memset(_inventory, 0, sizeof(_inventory));
}

Character::Character(const Character &other)
	: _name("Unknown"), _onFloorSize(0)
{
	std::memset(_inventory, 0, sizeof(_inventory));
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	for (int i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i]->clone();
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	for (std::size_t i = 0; i < _onFloorSize; i++)
		delete _onFloor[i];
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;

	_addItemOnFloor(_inventory[idx]);
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return;

	if (_inventory[idx] != NULL)
		_inventory[idx]->use(target);
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::_addItemOnFloor(AMateria *m)
{
	for (std::size_t i = 0; i < _onFloorSize; i++)
		if (_onFloor[i] == m)
			return;

	AMateria **newOnFloor = new AMateria*[_onFloorSize + 1];
	std::memcpy(newOnFloor, _onFloor, sizeof(AMateria*) * _onFloorSize);
	newOnFloor[_onFloorSize] = m;

	delete[] _onFloor;
	_onFloor = newOnFloor;
	_onFloorSize++;
}
