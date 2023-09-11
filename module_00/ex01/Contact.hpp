#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <string>

class Contact {
	public:
		Contact(void);

		bool ask(void);

		const std::string &getFirstName(void) const;
		const std::string &getLastName(void) const;
		const std::string &getNickname(void) const;
		const std::string &getPhoneNumber(void) const;
		const std::string &getDarkestSecret(void) const;
		const bool &getIsEmpty(void) const;


	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
		bool _isEmpty;
};

#endif  // CONTACT_HPP_
