#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <string>

class Weapon {
	public:
		Weapon(void);
		Weapon(const std::string& name);

		const std::string& getType(void) const;
		void setType(const std::string& type);


	private:
		std::string _type;
};

#endif  // WEAPON_HPP_
