#include <iostream>
#include <stdlib.h>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", false, 72, 45), _target("Unknown")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: AForm("RobotomyRequestForm", false, 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkExcutable(executor);

	std::cout << "Brrrrrrr...\n";
	if (rand() % 2 == 0)
		std::cout << _target << " has been successfully robotomized.\n";
	else
		std::cout << _target << " robotomization gone wrong.\n";
}
