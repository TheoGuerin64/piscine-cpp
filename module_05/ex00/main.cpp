#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

static void should_throw_error(std::string const &name)
{
	std::cout << "\033[0;31m" << name << " should throw an error\033[0m\n";
}

int main(void)
{
	try
	{
		Bureaucrat peter("Peter", 9999);
		should_throw_error("Peter");
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}

	try
	{
		Bureaucrat hugo("Hugo", 200);
		should_throw_error("Hugo");
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}

	try
	{
		Bureaucrat felix("Felix", -100);
		should_throw_error("Felix");
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}

	Bureaucrat michel("Michel", 2);
	std::cout << michel << "\n";
	michel.incrementGrade();
	std::cout << michel << "\n";

	try
	{
		michel.incrementGrade();
		should_throw_error("Michel");
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}

	Bureaucrat george("George", 149);
	std::cout << george << "\n";
	george.decrementGrade();
	std::cout << george << "\n";

	try
	{
		george.decrementGrade();
		should_throw_error("George");
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
}
