/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:10:55 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/17 15:18:46 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	// Fixed a(2);
	// Fixed b(3.2f);
	// Fixed c(0);
	// const Fixed d(4.15f);
	// const Fixed f(5.3f);

	// // Comparison operators and Arithmetic operators
	// {
	// 	std::cout << " a < b = " << (a < b) << std::endl;
	// 	std::cout << " a <= b = " << (a <= b) << std::endl;
	// 	std::cout << " a > b = " << (a > b) << std::endl;
	// 	std::cout << " a >= b = " << (a >= b) << std::endl;
	// 	std::cout << " a == b = " << (a == b) << std::endl;
	// 	std::cout << " a != b = " << (a != b) << std::endl;

	// 	std::cout << " a + b = " << (a + b) << std::endl;
	// 	std::cout << " a - b = " << (a - b) << std::endl;
	// 	std::cout << " a / b = " << (a / b) << std::endl;
	// 	std::cout << " a / c = " << (a / c) << std::endl;
	// 	std::cout << " a * b = " << (a * b) << std::endl;
	// 	std::cout << " a * c = " << (a * c) << std::endl;
	// }

	// {
	// 	std::cout << " nbr = " << a << std::endl;
	// 	std::cout << " preinc = " << ++a << std::endl;
	// 	std::cout << " nbr = " << a << std::endl;
	// 	std::cout << " postinc = " << a++ << std::endl;
	// 	std::cout << " nbr = " << a << std::endl;
	// 	std::cout << " nbr = " << b << std::endl;
	// 	std::cout << " predec = " << --b << std::endl;
	// 	std::cout << " nbr = " << b << std::endl;
	// 	std::cout << " postdec = " << b-- << std::endl;
	// 	std::cout << " nbr = " << b << std::endl;
	// }

	// std::cout << " max(a, b) = " << Fixed::max(a, b) << std::endl;
	// std::cout << " min(a, b) = " << Fixed::min(a, b) << std::endl;
	// std::cout << " max(d, f) = " << Fixed::max(d, f) << std::endl;
	// std::cout << " min(d, f) = " << Fixed::min(d, f) << std::endl;

	return (0);
}
