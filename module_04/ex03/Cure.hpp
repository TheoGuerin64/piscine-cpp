#ifndef CURE_HPP_
#define CURE_HPP_

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure(void);
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		~Cure();

		AMateria *clone() const;
		void use(ICharacter& target);
};

#endif  // CURE_HPP_
