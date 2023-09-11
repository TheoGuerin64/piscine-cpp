#ifndef FRAGTRAP_HPP_
#define FRAGTRAP_HPP_

#include <string>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &other);
		FragTrap &operator=(FragTrap const &other);
		~FragTrap();

		void highFivesGuys(void) const;
};

#endif  // FRAGTRAP_HPP_
