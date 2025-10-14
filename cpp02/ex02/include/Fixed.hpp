/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:11:00 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/14 19:25:39 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	bitsPoint = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed( const Fixed& copy);
		Fixed& operator = (const Fixed& other);
		~Fixed();
		int	getRawBits(void) const;
		int	getBinaryPoint( void ) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<( std::ostream &outstream, const Fixed& obj);
bool			operator>(const Fixed& a, const Fixed& b);
bool			operator<(const Fixed& a, const Fixed& b);
bool			operator==(const Fixed& a, const Fixed& b);
bool			operator!=(const Fixed& a, const Fixed& b);
Fixed			operator+(const Fixed& a, const Fixed& b);
Fixed			operator-(const Fixed& a, const Fixed& b);
Fixed			operator*(const Fixed& a, const Fixed& b);
Fixed			operator/(const Fixed& a, const Fixed& b);

#endif
