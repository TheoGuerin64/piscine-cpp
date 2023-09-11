#ifndef HARL_HPP_
#define HARL_HPP_

#include <string>

class Harl {
	public:
		Harl(void);
		~Harl();

		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void complain(std::string level);

	private:
		std::string _levels[4];

		int _levelToInt(const std::string &level);
};

#endif  // HARL_HPP_
