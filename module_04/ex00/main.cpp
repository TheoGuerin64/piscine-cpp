#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define BOLD "\033[1m"
#define RESET "\033[0m"

void subjectMain(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
}

void subjectMainWongAnimal(void)
{
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
}

int main(void)
{
	std::cout << BOLD "Subject main :\n" RESET;
	subjectMain();
	std::cout << "\n";

	std::cout << BOLD "Subject main with wrong animals :\n" RESET;
	subjectMainWongAnimal();
	std::cout << "\n";

	Animal a;
	Animal b(a);
	Animal c;
	c = b;
	std::cout << c.getType() << " " << std::endl;

	Cat d;
	Cat e(d);
	Cat f;
	f = e;
	std::cout << f.getType() << " " << std::endl;

	Dog g;
	Dog h(g);
	Dog i;
	i = h;
	std::cout << i.getType() << " " << std::endl;

	a.makeSound();
	d.makeSound();
	g.makeSound();

	return 0;
}
