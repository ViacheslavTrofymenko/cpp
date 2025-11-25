/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:26:18 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/25 12:54:42 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	BitcoinExchange	btc;

	if (!btc.loadDatabase("data.csv"))
	{
		std::cerr << "Error: could not load exchange rate database." << std::endl;
		return (1);
	}

	btc.processInputFile(argv[1]);
	return (0);
}
