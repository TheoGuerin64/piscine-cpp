#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include <iomanip>

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

static bool isChar(std::string const &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return true;
	return false;
}

static bool isInt(std::string const &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (!std::isdigit(str[i]))
			return false;
	}
	if (str.length() > 11)
		return false;

	int value;
	std::stringstream ss(str);
	return ss >> value;
}

static bool isFloatSpecial(std::string const &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "inff")
		return true;
	return false;
}

static bool isFloat(std::string const &str)
{
	if (isFloatSpecial(str))
		return true;

	bool hasDot = false;
	for (size_t i = 0; i < str.length() - 1; i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (str[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
			continue;
		}
		if (!std::isdigit(str[i]))
			return false;
	}
	if (str[str.length() - 1] != 'f' || !hasDot)
		return false;

	float value;
	std::stringstream ss(str);
	return ss >> value;
}

static bool isDoubleSpecial(std::string const &str)
{
	if (str == "-inf" || str == "+inf" || str == "nan" || str == "inf")
		return true;
	return false;
}

static bool isDouble(std::string const &str)
{
	if (isDoubleSpecial(str))
		return true;

	bool hasDot = false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (str[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
			continue;
		}
		if (!std::isdigit(str[i]))
			return false;
	}
	if (!hasDot)
		return false;

	double value;
	std::stringstream ss(str);
	return ss >> value;
}


ScalarConverter::_DataType ScalarConverter::_getType(std::string const &str)
{
	if (str == "")
		return UNKNOWN;
	if (isChar(str))
		return CHAR;
	if (isInt(str))
		return INT;
	if (isFloat(str))
		return FLOAT;
	if (isDouble(str))
		return DOUBLE;
	return UNKNOWN;
}

template <typename T>
static void showConvertion(std::string const &str)
{
	T value;
	std::stringstream ss(str);
	ss >> value;

	std::cout << "char: ";
	if (value >= -128 && value <= 127 && !isFloatSpecial(str) && !isDoubleSpecial(str))
	{
		if (std::isprint(value))
			std::cout << "'" << static_cast<char>(value) << "'";
		else
			std::cout << "Non displayable";
	}
	else
		std::cout << "impossible";
	std::cout << "\n";

	std::cout << "int: ";
	if (!isFloatSpecial(str) && !isDoubleSpecial(str) && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
		std::cout << static_cast<int>(value);
	else
		std::cout << "impossible";
	std::cout << "\n";

	std::cout << "float: ";
	if (isFloatSpecial(str))
		std::cout << str;
	else if (!isDoubleSpecial(str))
		std::cout << std::showpoint <<  static_cast<float>(value) << "f";
	else
		std::cout << "impossible";
	std::cout << "\n";

	std::cout << "double: ";
	if (isDoubleSpecial(str))
		std::cout << str;
	else if (!isFloatSpecial(str))
		std::cout << std::showpoint << static_cast<double>(value);
	else
		std::cout << "impossible";
	std::cout << "\n";
}

void ScalarConverter::convert(std::string const &str)
{
	_DataType type;

	type = _getType(str);
	switch (type)
	{
	case CHAR:
		showConvertion<char>(str);
		break;

	case INT:
		showConvertion<int>(str);
		break;

	case FLOAT:
		showConvertion<float>(str);
		break;

	case DOUBLE:
		showConvertion<double>(str);
		break;

	default:
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		break;
	}
}
