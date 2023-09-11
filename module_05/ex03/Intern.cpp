#include <string>
#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

std::string const Intern::_forms[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

Intern::Intern(void)
{}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{}

int Intern::_getFormIndex(std::string const &name) const
{
	for (int i = 0; i < 3; i++)
	{
		if (name == Intern::_forms[i])
			return i;
	}
	return -1;
}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
	int index = _getFormIndex(name);
	if (index == -1)
		std::cout << "Intern can't creates " << name << "\n";
	else
		std::cout << "Intern creates " << name << "\n";

	switch (index) {
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			return NULL;
	}
}
