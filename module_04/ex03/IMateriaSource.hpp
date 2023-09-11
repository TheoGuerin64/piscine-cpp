#ifndef IMATERIASOURCE_HPP_
#define IMATERIASOURCE_HPP_

#include <string>

class IMateriaSource;

#include "AMateria.hpp"

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria *) = 0;
		virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif  // IMATERIASOURCE_HPP_
