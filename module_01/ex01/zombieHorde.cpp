#include <string>

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];
	if (!zombies)
		return (NULL);

	for (int i = 0 ; i < N ; i++)
		zombies[i].setName(name);

	return zombies;
}
