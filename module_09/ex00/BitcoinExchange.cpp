#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>
#include <utility>

#include "BitcoinExchange.hpp"

int const BitcoinExchange::dayPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

static bool isValidBitcoinDate(std::string const &dateString)
{
	tm date;
	char const *remainder = strptime(dateString.c_str(), "%Y-%m-%d", &date);
	if (!remainder || remainder[0] || date.tm_year < 2009 - 1900)
		return false;
	if (isLeapYear(date.tm_year + 1900))
	{
		if (date.tm_mon == 1 && date.tm_mday > 29)
			return false;
		return true;
	}
	else if (date.tm_mday > BitcoinExchange::dayPerMonth[date.tm_mon])
		return false;
	return true;
}

static bool isValidFloat(std::string const &floatString)
{
	bool hasDot = false;
	for (size_t i = 0; i < floatString.size(); i++)
	{
		if (i == 0 && (floatString[i] == '-' || floatString[i] == '+'))
			continue;

		if (floatString[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(floatString[i]))
			return false;
	}
	return true;
}

BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream dataStream(DATA_FILE);
	if (!dataStream.is_open())
	{
		throw InvalidFileException();
	}

	std::string line;
	std::getline(dataStream, line);
	if (line != "date,exchange_rate")
	{
		throw BadInputException(line);
	}
	while (std::getline(dataStream, line))
	{
		std::pair<std::string, float> parsedLine = parseLine(line, ",");
		_data.insert(parsedLine);
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
	: _data(other._data)
{}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

std::pair<std::string, float> BitcoinExchange::parseLine(std::string const &line, std::string const &delimiter)
{
	if (line.size() < 11 + delimiter.size())
		throw BadInputException(line);

	std::string date = line.substr(0, 10);
	if (!isValidBitcoinDate(date))
		throw BadInputException(line);

	if (line.substr(10, delimiter.length()) != delimiter)
		throw BadInputException(line);

	float value;
	std::stringstream ss(line.substr(10 + delimiter.length()));
	if (!(ss >> value) || !isValidFloat(line.substr(10 + delimiter.length())))
		throw BadInputException(line);
	if (value < 0.f)
		throw NegativeValueException();
	if (value > 1000.f && delimiter == " | ")
		throw TooLargeException();

	return std::pair<std::string, float>(date, value);
}

float BitcoinExchange::getExchangeRate(std::string const &date) const
{
	for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); it++)
	{
		if (it->first == date)
			return it->second;
		else if (it->first > date)
		{
			if (it == _data.begin())
				return it->second;
			else
				return (--it)->second;
		}
	}
	return _data.rbegin()->second;
}

char const *BitcoinExchange::NegativeValueException::what(void) const throw()
{
	return "not a positive number.";
}

BitcoinExchange::BadInputException::BadInputException(std::string const &input) throw()
	: _message("bad input => " + input)
{}

BitcoinExchange::BadInputException::~BadInputException(void) throw()
{}

char const *BitcoinExchange::BadInputException::what(void) const throw()
{
	return _message.c_str();
}

char const *BitcoinExchange::TooLargeException::what(void) const throw()
{
	return "too large a number.";
}

char const *BitcoinExchange::InvalidFileException::what(void) const throw()
{
	return "could not open file.";
}
