#ifndef MATERIASOURCE_HPP_
#define MATERIASOURCE_HPP_

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
		~MateriaSource();

		void learnMateria(AMateria *materia);
		AMateria *createMateria(std::string const &type);


	private:
		AMateria *_inventory[4];
};

#endif  // MATERIASOURCE_HPP_
