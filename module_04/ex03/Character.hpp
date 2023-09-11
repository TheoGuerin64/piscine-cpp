#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();

		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

		std::string const &getName() const;


	private:
		std::string _name;
		AMateria *_inventory[4];
		AMateria **_onFloor;
		std::size_t _onFloorSize;

		void _addItemOnFloor(AMateria *m);
};

#endif  // CHARACTER_HPP_
