#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

#include <string>
#include <exception>
#include <map>

#define DATA_FILE "data.csv"

class BitcoinExchange {
	public:
		static int const dayPerMonth[12];

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);
		~BitcoinExchange();

		std::pair<std::string, float> parseLine(std::string const &line, std::string const &delimiter);
		float getExchangeRate(std::string const &date) const;

		class ParseException : public std::exception {
			public:
				virtual char const *what(void) const throw() = 0;
		};
		class NegativeValueException : public ParseException {
			public:
				virtual char const *what(void) const throw();
		};
		class BadInputException : public ParseException {
			public:
				BadInputException(std::string const &input) throw();
				~BadInputException(void) throw();

				virtual char const *what(void) const throw();


			private:
				std::string const _message;
		};
		class TooLargeException : public ParseException {
			public:
				virtual char const *what(void) const throw();
		};
		class InvalidFileException : public ParseException {
			public:
				virtual char const *what(void) const throw();
		};

	private:
		std::map<std::string, float> _data;
};

#endif  // BITCOINEXCHANGE_HPP_
