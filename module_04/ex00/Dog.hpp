#ifndef DOG_HPP_
#define DOG_HPP_

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();

		void makeSound(void) const;
};

#endif  // DOG_HPP_
