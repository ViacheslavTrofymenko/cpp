/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:50:00 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/26 13:43:06 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"
#include <stdexcept>
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN \"<RPN expression>\"" << std::endl;
		return 1;
	}

	try
	{
		RPN calculator;
		int result = calculator.calculate(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return (0);
}
