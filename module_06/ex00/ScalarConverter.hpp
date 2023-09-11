#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

#include <string>

class ScalarConverter {
	public:
		static void convert(std::string const &str);


	private:
		typedef enum {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			UNKNOWN
		} _DataType;

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();

		static ScalarConverter::_DataType _getType(std::string const &str);
};

#endif  // SCALARCONVERTER_HPP_
