#ifndef ABSTRACT_ANIMAL_HPP_
#define ABSTRACT_ANIMAL_HPP_

#include <string>

#include "Brain.hpp"

class AbstractAnimal {
	public:
		AbstractAnimal(void);
		AbstractAnimal(const AbstractAnimal &other);
		AbstractAnimal &operator=(const AbstractAnimal &other);
		virtual ~AbstractAnimal();

		virtual void makeSound(void) const = 0;

		std::string const &getType(void) const;


	protected:
		std::string _type;
};

#endif  // ABSTRACT_ANIMAL_HPP_
