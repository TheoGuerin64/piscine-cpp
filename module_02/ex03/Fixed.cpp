#include <iostream>
#include <cmath>

#include "Fixed.hpp"

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(const int value)
{
	_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	_rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	_rawBits = other.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
	return _rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed &other) const
{
	return _rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return _rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return _rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed &other) const
{
	return _rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return _rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void)
{
	_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_rawBits++;
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_rawBits--;
	return tmp;
}

Fixed::~Fixed() {}

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
