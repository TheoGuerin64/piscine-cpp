#include <iostream>
#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value) : _rawBits(0)
{
	std::cout << "Int constructor called\n";
	_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) : _rawBits(0)
{
	std::cout << "Float constructor called\n";
	_rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	_rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

float Fixed::toFloat(void) const
{
	return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _rawBits >> _fractionalBits;
}

int Fixed::getRawBits(void) const
{
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &dt)
{
	os << dt.toFloat();
	return os;
}
