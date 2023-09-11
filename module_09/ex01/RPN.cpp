#include <string>
#include <iostream>
#include <exception>

#include "RPN.hpp"

/* public */

static bool isSpaceSepared(std::string const &calcul)
{
	for (std::size_t i = 0; i < calcul.size(); i++)
	{
		if (calcul[i] == ' ' && i % 2 == 0)
			return false;
		else if (calcul[i] != ' ' && i % 2 == 1)
			return false;
	}
	return true;
}

int RPN::resolve(std::string const &calcul)
{
	if (!isSpaceSepared(calcul) || calcul.empty() || calcul.size() % 2 == 0)
		throw CalculNotValidException();

	std::stack<int> stack;
	for (std::string::const_iterator it = calcul.begin(); it != calcul.end(); it++)
	{
		if (*it == ' ')
			continue;
		if (std::isdigit(*it))
			stack.push(*it - '0');
		else if (RPN::_operators.find(*it) != std::string::npos)
		{
			if (stack.size() < 2)
				throw CalculNotValidException();

			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			stack.push(_resolveOperation(*it, b, a));
		}
		else
			throw CalculNotValidException();
	}
	if (stack.size() != 1)
		throw CalculNotValidException();
	return stack.top();
}

const char *RPN::CalculNotValidException::what(void) const throw()
{
	return "Calcul not valid";
}

/* private */

std::string const RPN::_operators = "+-*/";

RPN::RPN(void)
{}

RPN::RPN(RPN const &other)
{
	*this = other;
}

RPN &RPN::operator=(RPN const &other)
{
	(void)other;
	return *this;
}

RPN::~RPN()
{}

int RPN::_resolveOperation(char op, int a, int b)
{
	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0)
				throw CalculNotValidException();
			return a / b;
		default:
			throw CalculNotValidException();
	}
}
