#ifndef FIXED_HPP_
#define FIXED_HPP_

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);


	private:
		static const int _fractionalBits = 8;

		int _rawBits;
};

#endif  // FIXED_HPP_

#
