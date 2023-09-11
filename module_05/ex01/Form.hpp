#ifndef FORM_HPP_
#define FORM_HPP_

#include <string>

class Form;

#include "Bureaucrat.hpp"

class Form {
	public:
		Form(void);
		Form(std::string const &name, bool isSigned, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		void beSigned(Bureaucrat &bureaucrat);

		std::string const &getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw();
		};
		class AssignementException : public std::exception {
			public:
				char const *what(void) const throw();
		};


	private:
		std::string const _name;
		bool _isSigned;
		int const _gradeToSign;
		int const _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &dt);

#endif  // FORM_HPP_
