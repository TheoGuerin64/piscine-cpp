#include <string>

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main(void)
{
	Zombie *z = newZombie("George");
	if (!z)
		return 1;

	z->announce();
	randomChump("Patrick");

	delete z;
}
