/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:10:57 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/14 19:30:17 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	value = num << bitsPoint;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(num * (1 << bitsPoint));
}
Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = copy.value;
}
Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}
void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}
Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
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

bool	operator>(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() > b.getRawBits());
}

bool	operator<(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() < b.getRawBits());
}

bool	operator==(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() == b.getRawBits());
}

bool	operator!=(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() != b.getRawBits());
}

Fixed	operator+(const Fixed& a, const Fixed& b)
{
	Fixed	tmp;

	tmp.setRawBits(a.getRawBits() + b.getRawBits());
	return (tmp);
}

Fixed	operator-(const Fixed& a, const Fixed& b)
{
	Fixed	tmp;

	tmp.setRawBits(a.getRawBits() - b.getRawBits());
	return (tmp);
}

Fixed	operator*(const Fixed& a, const Fixed& b)
{
	Fixed	tmp;

	tmp.setRawBits((a.getRawBits() * b.getRawBits()) >> a.getBinaryPoint());
	return (tmp);
}

Fixed	operator/(const Fixed& a, const Fixed& b)
{
	Fixed	tmp;

	tmp.setRawBits((a.getRawBits() / b.getRawBits()) << a.getBinaryPoint());
	return (tmp);
}

Fixed&	Fixed::operator++( void )
{
	(this->value)++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	old;

	old = *this;
	(this->value)++;
	return (old);
}

Fixed&	Fixed::operator--( void )
{
	(this->value)--;
	return (*this);
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
