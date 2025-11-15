/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:17:16 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/15 17:33:15 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Span.hpp"

int main()
{
	Span sp = Span(7);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	int arr[] = {1, 5};
	sp.addNumbers(arr, arr + 2);
	try
	{
		sp.addNumber(20);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	Span sp2 = sp;
	std::cout << "Copy Test - Shortest Span: " << sp2.shortestSpan() << std::endl;
	Span sp3(3);
	sp3 = sp;
	std::cout << "Assignment Test - Longest Span: " << sp3.longestSpan() << std::endl;
	return (0);
}
