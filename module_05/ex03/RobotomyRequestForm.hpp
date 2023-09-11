#ifndef ROBOTOMYREQUESTFORM_HPP_
#define ROBOTOMYREQUESTFORM_HPP_

#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const;


	private:
		std::string const _target;
};

#endif  // ROBOTOMYREQUESTFORM_HPP_
