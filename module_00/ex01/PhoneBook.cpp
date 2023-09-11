#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _contactAdded(0) {}

void PhoneBook::add(void)
{
	if (_contacts[_contactAdded % 8].ask())
		_contactAdded += 1;
}

static void printCell(std::string value)
{
	if (value.length() > 10)
		std::cout << value.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << value.substr(0, 10);
}

static void printCell(int value)
{
	std::cout << std::setw(10) << value;
}

static void printContacts(Contact contacts[8])
{
	for (int j = 0 ; j < 4 ; j++)
	{
		if (j == 0)
			printCell("index");
		else if (j == 1)
			printCell("first name");
		else if (j == 2)
			printCell("last name");
		else if (j == 3)
			printCell("nickname");
		for (int i = 0 ; i < 8 && !contacts[i].getIsEmpty() ; i++)
		{
			std::cout << "|";
			if (j == 0)
				printCell(i);
			else if (j == 1)
				printCell(contacts[i].getFirstName());
			else if (j == 2)
				printCell(contacts[i].getLastName());
			else if (j == 3)
				printCell(contacts[i].getNickname());
		}
		std::cout << std::endl;
	}
}

static void showContact(Contact contacts[8])
{
	std::string line;
	int	index;

	std::cout << "Index to show: ";
	std::getline(std::cin, line);

	std::stringstream stream(line);
	if (!(stream >> index))
	{
		std::cout << "This is not a valid integer!" << std::endl;
		return;
	}
	if (index < 0 || index > 7 || contacts[index].getIsEmpty())
	{
		std::cout << "Index out of range!" << std::endl;
		return;
	}

	std::cout << "Fist name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::search(void)
{
	if (_contacts[0].getIsEmpty())
	{
		std::cout << "The PhoneBook is empty.\n";
		return;
	}
	std::cout << std::right;
	printContacts(_contacts);
	std::resetiosflags(std::ios::adjustfield);
	showContact(_contacts);
}
