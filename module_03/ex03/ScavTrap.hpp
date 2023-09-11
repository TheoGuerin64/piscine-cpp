#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &other);
		ScavTrap &operator=(ScavTrap const &other);
		~ScavTrap();

		void attack(std::string const &target);
		void guardGate(void) const;
};

#endif  // SCAVTRAP_HPP_
