#ifndef HUMANA_HPP_
#define HUMANA_HPP_

#include <string>

#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(const std::string &name, const Weapon &Weapon);

		void attack(void) const;


	private:
		const std::string _name;
		const Weapon &_weapon;

		HumanA();
};

#endif  // HUMANA_HPP_
