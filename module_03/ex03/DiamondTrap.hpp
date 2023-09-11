#ifndef DIAMONDTRAP_HPP_
#define DIAMONDTRAP_HPP_

#include <string>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	public:
		DiamondTrap(void);
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &other);
		DiamondTrap &operator=(DiamondTrap const &other);
		~DiamondTrap();

		void attack(std::string const &target);
		void whoAmI(void) const;

	private:
		std::string _name;
};

#endif  // DIAMONDTRAP_HPP_
