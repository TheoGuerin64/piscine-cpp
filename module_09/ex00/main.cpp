#include <iostream>
#include <fstream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file.\n";
		return 1;
	}

	BitcoinExchange *bitcoin;
	try
	{
		bitcoin = new BitcoinExchange();
	}
	catch (BitcoinExchange::ParseException &e)
	{
		std::cout << "Error: could not parse data.\n";
		return 1;
	}

	std::ifstream fileStream(argv[1]);
	if (!fileStream.is_open())
	{
		delete bitcoin;
		std::cout << "Error: could not open file.\n";
		return 1;
	}

	std::string line;
	std::getline(fileStream, line);
	if (line != "date | value")
	{
		delete bitcoin;
		std::cout << "File format is not correct.\n";
		return 1;
	}
	while (std::getline(fileStream, line))
	{
		try
		{
			std::pair<std::string, float> dateValue = bitcoin->parseLine(line, " | ");
			float exchangeRate = bitcoin->getExchangeRate(dateValue.first);

			std::cout << dateValue.first << " => " << dateValue.second << " = "
					  << dateValue.second * exchangeRate << std::endl;
		}
		catch (BitcoinExchange::ParseException &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	delete bitcoin;
	return 0;
}
