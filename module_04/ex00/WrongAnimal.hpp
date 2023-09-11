#ifndef WRONGANIMAL_HPP_
#define WRONGANIMAL_HPP_

#include <string>

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		virtual ~WrongAnimal();

		void makeSound(void) const;

		std::string const &getType(void) const;


	protected:
		std::string _type;
};

#endif  // WRONGANIMAL_HPP_
