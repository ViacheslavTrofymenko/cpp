/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:10:57 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/14 12:22:36 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
