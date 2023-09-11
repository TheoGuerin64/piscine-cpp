#include <string>

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
	Zombie *zombies = zombieHorde(5, "George");
	if (!zombies)
		return (1);

	for (int i = 0 ; i < 5 ; i++)
		zombies[i].announce();

	delete[] zombies;
}
