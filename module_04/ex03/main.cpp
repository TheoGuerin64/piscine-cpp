#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void subject_main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void my_main(void)
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	delete bob;
	delete me;
	delete src;
}

int main(void)

{
	std::cout << "==========================" << std::endl;
	std::cout << "=== SUBJECT MAIN START ===" << std::endl;
	std::cout << "==========================" << std::endl;

	subject_main();

	std::cout << "==========================" << std::endl;
	std::cout << "=== SUBJECT MAIN END =====" << std::endl;
	std::cout << "==========================" << std::endl;

	std::cout << std::endl;

	std::cout << "==========================" << std::endl;
	std::cout << "=== MY MAIN START ========" << std::endl;
	std::cout << "==========================" << std::endl;

	my_main();

	std::cout << "==========================" << std::endl;
	std::cout << "=== MY MAIN END ==========" << std::endl;
	std::cout << "==========================" << std::endl;

	return 0;
}
