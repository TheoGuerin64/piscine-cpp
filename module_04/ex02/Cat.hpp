#ifndef CAT_HPP_
#define CAT_HPP_

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Cat : public AbstractAnimal {
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();

		void makeSound(void) const;
		std::string const &getIdea(int index) const;
		void setIdea(int index, std::string const &value);

		Brain const *getBrain(void) const;


	private:
		Brain *_brain;
};

#endif  // CAT_HPP_
