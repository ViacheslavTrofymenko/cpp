/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:10:57 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/29 21:24:58 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(): value(0)
{}
Fixed::Fixed(const int num)
{
	value = num << bitsPoint;
}

Fixed::Fixed(const float num)
{
	value = roundf(num * (1 << bitsPoint));
}
Fixed::Fixed(const Fixed& copy)
{
	this->value = copy.value;
}
Fixed::~Fixed() {}

int		Fixed::getRawBits( void ) const
{
	return this->value;
}
void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}
Fixed&	Fixed::operator=(const Fixed& other)
{
	this->value = other.value;
	return (*this);
}

float	Fixed::toFloat( void ) const
{
	float	tmp;

	tmp = value >> bitsPoint;
	tmp += (float)(value & ((1 << bitsPoint) - 1)) / (1 << bitsPoint);
	return tmp;
}

int	Fixed::toInt ( void ) const
{
	return this->value >> bitsPoint;
}

std::ostream&	operator<<( std::ostream &outstream, const Fixed& obj)
{
	float	tmp;

	tmp = obj.toFloat();
	outstream << tmp;
	return outstream;
}

int	Fixed::getBinaryPoint( void ) const
{
	return this->bitsPoint;
}

// Comparison operators
bool	Fixed::operator>(const Fixed& fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(const Fixed& fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}
bool	Fixed::operator>=(const Fixed& fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

// Arithmetic Operators
Fixed	Fixed::operator+(const Fixed& fixed) const
{
	Fixed	tmp(this->toFloat() + fixed.toFloat());

	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& fixed) const
{
	Fixed tmp(this->toFloat() - fixed.toFloat());
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed& fixed) const
{
	Fixed	tmp(this->toFloat() * fixed.toFloat());
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& fixed) const
{
	if (fixed.getRawBits() == 0)
	{
		std::cout << "You tried to divide by zero. This is prohibited" << std::endl;
		return (Fixed(0));
	}
	Fixed	tmp(this->toFloat() / fixed.toFloat());
	return (tmp);
}

	//Pre-increment operators
Fixed&	Fixed::operator++( void )
{
	(this->value)++;
	return (*this);
}

Fixed&	Fixed::operator--( void )
{
	(this->value)--;
	return (*this);
}

// Post-increment operators
Fixed	Fixed::operator++( int )
{
	Fixed	old;

	old = *this;
	(this->value)++;
	return (old);
}

Fixed	Fixed::operator--( int )
{
	Fixed	old;

	old = *this;
	(this->value)--;
	return (old);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}
