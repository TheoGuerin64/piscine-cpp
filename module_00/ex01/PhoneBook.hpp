#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(void);

		void add(void);
		void search(void);

	private:
		Contact _contacts[8];
		int _contactAdded;
};

#endif  // PHONEBOOK_HPP_
