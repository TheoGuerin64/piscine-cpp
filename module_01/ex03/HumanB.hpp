#ifndef HUMANB_HPP_
#define HUMANB_HPP_

#include <string>

#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(const std::string &name);

		void attack(void) const;

		void setWeapon(Weapon &weapon);


	private:
		const std::string _name;
		Weapon *_weapon;

		HumanB();
};

#endif  // HUMANB_HPP_
