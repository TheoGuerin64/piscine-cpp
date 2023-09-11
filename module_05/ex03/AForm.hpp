#ifndef AFORM_HPP_
#define AFORM_HPP_

#include <string>

class AForm;

#include "Bureaucrat.hpp"

class AForm {
	public:
		AForm(void);
		AForm(std::string const &name, bool isSigned, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
		void checkExcutable(Bureaucrat const &executor) const;

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
				const char *what(void) const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char *what(void) const throw();
		};

	private:
		std::string const _name;
		bool _isSigned;
		int const _gradeToSign;
		int const _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const AForm &dt);

#endif  // AFORM_HPP_
