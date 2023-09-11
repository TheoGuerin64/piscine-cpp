#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <string>

class Zombie {
	public:
		Zombie(void);
		Zombie(const std::string &name);
		~Zombie();

		void announce(void) const;

		void setName(const std::string &name);


	private:
		std::string _name;
};

#endif  // ZOMBIE_HPP_
