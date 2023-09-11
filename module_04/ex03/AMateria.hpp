#ifndef AMATERIA_HPP_
#define AMATERIA_HPP_

#include <string>

class AMateria;

#include "ICharacter.hpp"

class AMateria {
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();

		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter& target);

		virtual std::string const &getType() const;


	protected:
		std::string _type;
};

#endif  // AMATERIA_HPP_
