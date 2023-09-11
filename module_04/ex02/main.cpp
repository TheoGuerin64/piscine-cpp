#include <string>
#include <iostream>

#include "AbstractAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define ANIMAL_NB 4

void subjectMain(void)
{
	const AbstractAnimal* j = new Dog();
	const AbstractAnimal* i = new Cat();
	delete j;
	delete i;
}

int main(void)
{
	// AbstractAnimal error;

	std::cout << BOLD "Subject main :\n" RESET;
	subjectMain();
	std::cout << "\n";

	AbstractAnimal *array[ANIMAL_NB];
	for (int i = 0; i < ANIMAL_NB; i++)
	{
		if (i < ANIMAL_NB / 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}

	((Dog *)array[0])->setIdea(0, "Salut");
	std::cout << "Idea 0: " << ((Dog *)array[0])->getIdea(0) << "\n";
	std::cout << "Idea 1: " << ((Dog *)array[1])->getIdea(0) << "\n";
	*(Dog *)array[1] = *(Dog *)array[0];
	((Dog *)array[0])->setIdea(0, "Bye");
	std::cout << "Idea 0: " << ((Dog *)array[0])->getIdea(0) << "\n";
	std::cout << "Idea 1: " << ((Dog *)array[1])->getIdea(0) << "\n";

	for (int i = 0; i < ANIMAL_NB; i++)
		delete array[i];

	return 0;
}
