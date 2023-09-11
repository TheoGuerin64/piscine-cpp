#include <iostream>
#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", false, 145, 137), _target("Unknown")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("ShrubberyCreationForm", false, 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkExcutable(executor);

	std::string file_name = _target + "_shrubbery";
	std::ofstream file(file_name.c_str());
	if (!file.is_open()) {
		std::cout << "Error: cannot open file " << file_name << std::endl;
		return;
	}
	file.write(ASCII_TREE, sizeof(ASCII_TREE) - 1);
	file.close();
}
