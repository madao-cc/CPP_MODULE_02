/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:20:08 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/17 11:25:25 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::bits = 8;

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

// CONVERTS THE INTEGER VALUE TO A FIXED POINT VALUE.
// THIS FUNCTION WILL SHIFT THE INTEGER VALUE LEFT BY THE NUMBER OF BITS (8).
// THIS EFFECTIVELY MULTIPLIES THE INTEGER VALUE BY 2^8 = 256.
// THIS MOVES THE INTEGER PART TO THE HIGHER BITS AND LEAVING THE LOWER BITS FOR THE DECIMAL PART.
Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->bits;
}

// CONVERTS THE FLOATING POINT VALUE TO A FIXED POINT VALUE.
// THIS FUNCTION WILL ROUND THE FLOATING POINT VALUE TO THE NEAREST INTEGER.
// THEN IT WILL SHIFT THE INTEGER VALUE LEFT BY THE NUMBER OF BITS (8).
// THIS EFFECTIVELY MULTIPLIES THE INTEGER VALUE BY 2^8 = 256.
// THIS MOVES THE INTEGER PART TO THE HIGHER BITS AND LEAVING THE LOWER BITS FOR THE DECIMAL PART.
Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->bits));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// THIS FUNCTION WILL CONVERT THE FIXED POINT VALUE TO A FLOATING POINT VALUE.
// THIS DIVIDES THE FIXED POINT VALUE BY 256.
// MOVING THE FRACTIONAL PART BACK TO THE CORRECT POSITION.
float	Fixed::toFloat(void) const
{
	return (this->_value / 256.0);
}

// THIS FUNCTION WILL CONVERT THE FIXED POINT VALUE TO AN INTEGER VALUE.
// THIS DIVIDES THE FIXED POINT VALUE BY 256.
// DISCARDING THE FRACTIONAL PART.
int	Fixed::toInt(void) const
{
	return (this->_value / 256);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

Fixed	&Fixed::operator=(Fixed const &src) 
{
	// std::cout << "Assignation operator called" << std::endl;
	this->_value = src.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}

Fixed	Fixed::operator+(Fixed const &src) const
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &src) const
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &src) const
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &src) const
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

bool	Fixed::operator>(Fixed const &src) const
{
	return (this->toFloat() > src.toFloat());
}

bool	Fixed::operator<(Fixed const &src) const
{
	return (this->toFloat() < src.toFloat());
}

bool	Fixed::operator>=(Fixed const &src) const
{
	return (this->toFloat() >= src.toFloat());
}

bool	Fixed::operator<=(Fixed const &src) const
{
	return (this->toFloat() <= src.toFloat());
}

bool	Fixed::operator==(Fixed const &src) const
{
	return (this->toFloat() == src.toFloat());
}

bool	Fixed::operator!=(Fixed const &src) const
{
	return (this->toFloat() != src.toFloat());
}

Fixed	&Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	operator++();
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	operator--();
	return (tmp);
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{

	return (a < b ? a : b);
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}
