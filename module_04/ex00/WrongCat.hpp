#ifndef WRONGCAT_HPP_
#define WRONGCAT_HPP_

#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		~WrongCat();

		void makeSound(void) const;
};

#endif  // WRONGCAT_HPP_
