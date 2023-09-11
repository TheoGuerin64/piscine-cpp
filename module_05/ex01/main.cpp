#include <string>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Form paymentBill("Payment bill", false, -1, 2);
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Form paymentBill("Payment bill", false, 1, 255);
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << e.what() << '\n';
	}

	Form paymentBill("Payment bill", false, 1, 2);
	std::cout << paymentBill << std::endl;

	Bureaucrat boss("Boss", 1);
	std::cout << boss << std::endl;

	Bureaucrat accountant("Accountant", 2);
	std::cout << accountant << std::endl;

	Bureaucrat worker("Worker", 3);
	std::cout << worker << std::endl;

	try
	{
		accountant.signForm(paymentBill);
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << e.what() << '\n';
	}
	boss.signForm(paymentBill);
}
