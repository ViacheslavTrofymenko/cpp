/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:10:55 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/17 17:08:11 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"


int main(void)
{
	bool	result;

	{
	const Point	a ( -2.0f, 5.0f );
	const Point	b ( 3.0f, 5.0f );
	const Point	c ( 0.0f, 0.0f );
	const Point	p ( 0.0f, 4.0f );

	result = bsp(a, b, c, p);
	std::cout << "result = " << result << std::endl;
	}

	{
	const Point	a ( 0.0f, 5.0f );
	const Point	b ( 5.0f, 5.0f );
	const Point	c ( 0.0f, 0.0f );
	const Point	p ( 3.0f, 5.0f );

	result = bsp(a, b, c, p);
	std::cout << "result = " << result << std::endl;
	}

	{
	const Point	a ( 0.0f, 5.0f );
	const Point	b ( 5.0f, 5.0f );
	const Point	c ( 0.0f, 0.0f );
	const Point	p ( -3.0f, 5.0f );

	result = bsp(a, b, c, p);
	std::cout << "result = " << result << std::endl;
	}

	return (0);

}
