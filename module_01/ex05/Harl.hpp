#ifndef HARL_HPP_
#define HARL_HPP_

#include <string>

class Harl {
	public:
		Harl(void);

		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void complain(std::string level);

	private:
		struct _level
		{
			std::string name;
			void (Harl::*ptr)(void);
		};

		_level _levels[4];
};

#endif  // HARL_HPP_
