#include <string>
#include <iostream>
#include <stdlib.h>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat boss("Boss", 1);
	Bureaucrat worker("Worker", 100);

	ShrubberyCreationForm shrub("Trees");
	shrub.beSigned(boss);

	RobotomyRequestForm robot("Robot");
	robot.beSigned(boss);

	PresidentialPardonForm pardon("Pardon");
	pardon.beSigned(boss);

	shrub.execute(boss);
	robot.execute(boss);
	pardon.execute(boss);

	worker.executeForm(shrub);
	worker.executeForm(robot);
	worker.executeForm(pardon);
}
