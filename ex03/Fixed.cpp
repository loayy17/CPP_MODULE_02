#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _value(0)
{
}
Fixed::Fixed(const Fixed &other)
{
	if (this != &other)
		this->_value = other._value;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		// variable;
		this->_value = other._value;
	}
	return (*this);
}
int Fixed::getRawBits() const
{
	return (_value);
}
void Fixed::setRawBits(int const value)
{
	_value = value;
}

Fixed::Fixed(const int integer)
{
	_value = integer << _fractionalBits;
}
Fixed::Fixed(const float number)
{
	_value = (int)(roundf(number * (1 << _fractionalBits)));
}
float Fixed::toFloat(void) const
{
	return (float)(_value) / (1 << _fractionalBits);
}
int Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

// Overload the insertion operator for Fixed class
bool Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}
bool Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}
bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}
bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}
bool Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}
Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}
Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}
Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}
Fixed Fixed::operator/(const Fixed &other) const
{
	if (other._value == 0)
	{
		throw std::runtime_error("Division by zero");
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}
Fixed &Fixed::operator++()
{
	++this->_value;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++this->_value;
	return (temp);
}
Fixed &Fixed::operator--()
{
	--this->_value;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--this->_value;
	return (temp);
}
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
