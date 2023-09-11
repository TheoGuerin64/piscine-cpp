#include <string>
#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", false, 25, 5), _target("Unknown")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: AForm("PresidentialPardonForm", false, 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	checkExcutable(executor);

	std::cout << _target << " has been pardoned by Zafod Beeblebrox.\n";
}
