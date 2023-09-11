#include <string>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void)
	: _name("Unknown"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
	: _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	(void)other;
	throw Bureaucrat::AssignementException();
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

void Bureaucrat::incrementGrade(void)
{
	_grade--;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
	_grade++;
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "\n";
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
	}
}

std::string const &Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

const char *Bureaucrat::AssignementException::what(void) const throw()
{
	return "The assignement operator should not be used on this class";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &dt)
{
	os << dt.getName() << ", bureaucrat grade " << dt.getGrade() << ".";
	return os;
}
