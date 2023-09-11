#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <string>

class Animal {
	public:
		Animal(void);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		virtual void makeSound(void) const;

		std::string const &getType(void) const;


	protected:
		std::string _type;
};

#endif  // ANIMAL_HPP_
