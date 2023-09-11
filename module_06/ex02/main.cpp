#include <string>
#include <iostream>
#include <stdlib.h>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	default:
		return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C\n";
}

void identify(Base &p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	} catch (std::exception &e) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	} catch (std::exception &e) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	} catch (std::exception &e) {}
}

int main(void)
{
	srand(time(NULL));

	Base *t = generate();
	identify(t);
	identify(*t);
}
