#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &other)
		this->_value = other._value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// variable;
		this->_value = other._value;
	}
	return (*this);
}
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}
void Fixed::setRawBits(int const value)
{
	_value = value;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	_value = integer << _fractionalBits;
}
Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	_value = (int)(roundf(number * (1 << _fractionalBits))); // 100000000 = 256
}
float Fixed::toFloat(void) const
{
	return (float)(_value) / (1 << _fractionalBits); // 256
}
int Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
// steps to convert float to fixed point
// 1. multiply the float by 2^fractionalBits (1 << fractionalBits)
// 2. round the result to the nearest integer
// 3. store the integer in the _value variable
// steps to int to fixed point
// 1. divide the integer by 2^fractionalBits (1 << fractionalBits)
// 2. return the result as an integer
// example:
// float number = 42.42f
// fractionalBits = 8
// 1. 42.42 * 256 = 10859.52
// 2. round(10859.52) = 10860
// 3. _value = 10860
// to convert back to float
// 1. 10860 / 256 = 42.421875
// to convert back to int
// 1. 10860 >> 8 = 42
