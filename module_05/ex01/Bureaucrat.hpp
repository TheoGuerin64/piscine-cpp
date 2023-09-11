#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <string>

class Bureaucrat;

#include "Form.hpp"

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(Form &form);

		std::string const &getName(void) const;
		int getGrade(void) const;

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


	private:
		const std::string _name;
		int _grade;

		Bureaucrat &operator=(const Bureaucrat &other);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &dt);

#endif  // BUREAUCRAT_HPP_
