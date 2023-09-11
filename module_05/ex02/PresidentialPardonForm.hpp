#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		void execute(Bureaucrat const &executor) const;


	private:
		std::string const _target;
};

#endif  // PRESIDENTIALPARDONFORM_HPP_
