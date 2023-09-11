#ifndef ICE_HPP_
#define ICE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice(void);
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice();

		AMateria *clone() const;
		void use(ICharacter& target);
};

#endif  // ICE_HPP_
