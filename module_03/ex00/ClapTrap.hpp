#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <string>

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &other);
		ClapTrap &operator=(ClapTrap const &other);
		~ClapTrap();

		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};

#endif  // CLAPTRAP_HPP_
