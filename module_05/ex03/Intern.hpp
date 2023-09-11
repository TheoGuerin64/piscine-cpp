#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <string>

#include "AForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm *makeForm(std::string const &name, std::string const &target);


	private:
		static std::string const _forms[3];

		int _getFormIndex(std::string const &name) const;
};

#endif  // INTERN_HPP_
