#include <string>
#include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
	: _name("Unknown"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{}

Form::Form(std::string const &name, bool isSigned, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150)
		throw Form::GradeTooLowException();

	if (_gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}

Form &Form::operator=(const Form &other)
{
	(void)other;
	throw Form::AssignementException();
	return *this;
}

Form::~Form()
{}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

std::string const &Form::getName(void) const
{
	return _name;
}

bool Form::getIsSigned(void) const
{
	return _isSigned;
}

int Form::getGradeToSign(void) const
{
	return _gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

const char *Form::AssignementException::what(void) const throw()
{
	return "The assignement operator should not be used on this class";
}

std::ostream &operator<<(std::ostream &os, const Form &dt)
{
	os << "Form " << dt.getName() << " is " << (dt.getIsSigned() ? "" : "not ")
		<< "signed and requires a grade of " << dt.getGradeToSign()
		<< " to sign and a grade of " << dt.getGradeToExecute() << " to execute";
	return os;
}
