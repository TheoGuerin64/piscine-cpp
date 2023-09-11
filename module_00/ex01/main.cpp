#include <iostream>

#include "PhoneBook.hpp"

int main()
{
	PhoneBook my_phonebook;
	std::string cmd;

	while (true)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << "EXIT" << std::endl;
			break;
		}

		if (cmd == "ADD")
			my_phonebook.add();
		else if (cmd == "SEARCH")
			my_phonebook.search();
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "This command doesn't exist!" << std::endl;
	}

	return 0;
}

