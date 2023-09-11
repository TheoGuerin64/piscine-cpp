#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		float toFloat(void) const;
		int toInt(void) const;

		int getRawBits(void) const;
		void setRawBits(int const raw);


	private:
		static const int _fractionalBits = 8;

		int _rawBits;
};

std::ostream& operator<<(std::ostream &os, const Fixed &dt);

#endif  // FIXED_HPP_
