#include <string>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
	: _name("Unknown"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{}

AForm::AForm(std::string const &name, bool isSigned, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150)
		throw AForm::GradeTooLowException();

	if (_gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}

AForm &AForm::operator=(const AForm &other)
{
	(void)other;
	throw AForm::AssignementException();
	return *this;
}

AForm::~AForm()
{}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void AForm::checkExcutable(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	if (!_isSigned)
		throw AForm::FormNotSignedException();
}

std::string const &AForm::getName(void) const
{
	return _name;
}

bool AForm::getIsSigned(void) const
{
	return _isSigned;
}

int AForm::getGradeToSign(void) const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

const char *AForm::AssignementException::what(void) const throw()
{
	return "The assignement operator should not be used on this class";
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return "The form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &dt)
{
	os << "AForm " << dt.getName() << " is " << (dt.getIsSigned() ? "" : "not ")
		<< "signed and requires a grade of " << dt.getGradeToSign()
		<< " to sign and a grade of " << dt.getGradeToExecute() << " to execute";
	return os;
}
