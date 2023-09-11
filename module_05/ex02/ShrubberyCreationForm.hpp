#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include <string>

#include "AForm.hpp"

#define ASCII_TREE \
"            ,@@@@@@@,\n" \
"    ,,,.   ,@@@@@@/@@,  .oo8888o.\n" \
" ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n" \
",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n" \
"%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n" \
"%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n" \
"`&%\\ ` /%&'    |.|        \\ '|8'\n" \
"    |o|        | |         | |\n" \
"    |.|        | |         | |\n" \
" \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n" \

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const &executor) const;


	private:
		std::string const _target;
};


#endif  // SHRUBBERYCREATIONFORM_HPP_
