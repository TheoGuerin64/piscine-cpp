#include <string>
#include <iostream>
#include <stdlib.h>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat boss = Bureaucrat("Boss", 1);
	Intern intern;

	AForm *form = intern.makeForm("robotomy request", "macron");
	std::cout << *form << "\n";

	AForm *bad_form = intern.makeForm("bad request", "macron");
	std::cout << bad_form << "\n";
}
