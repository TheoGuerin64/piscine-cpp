#ifndef DOG_HPP_
#define DOG_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();

		void makeSound(void) const;
		std::string const &getIdea(int index) const;
		void setIdea(int index, std::string const &value);

		Brain const *getBrain(void) const;


	private:
		Brain *_brain;
};

#endif  // DOG_HPP_
