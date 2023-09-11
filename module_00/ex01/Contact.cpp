#include <iostream>
#include <string>

#include "Contact.hpp"

Contact::Contact(void) : _isEmpty(true) {}

static bool askInfo(const std::string &name, std::string& value)
{
	std::cout << name << ": ";
	std::getline(std::cin, value);
	return !value.empty();
}

bool Contact::ask(void)
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	if (askInfo("first name", firstName)
		&& askInfo("last name", lastName)
		&& askInfo("nickname", nickname)
		&& askInfo("phone number", phoneNumber)
		&& askInfo("darkest secret", darkestSecret))
	{
		_firstName = firstName;
		_lastName = lastName;
		_nickname = nickname;
		_phoneNumber = phoneNumber;
		_darkestSecret = darkestSecret;
		_isEmpty = false;
		return true;
	}
	else
	{
		std::cout << "Fields should not be empty!\n";
		return false;
	}
}

const std::string &Contact::getFirstName(void) const
{
	return _firstName;
}

const std::string &Contact::getLastName(void) const
{
	return _lastName;
}

const std::string &Contact::getNickname(void) const
{
	return _nickname;
}

const std::string &Contact::getPhoneNumber(void) const
{
	return _phoneNumber;
}

const std::string &Contact::getDarkestSecret(void) const
{
	return _darkestSecret;
}

const bool &Contact::getIsEmpty(void) const
{
	return _isEmpty;
}
