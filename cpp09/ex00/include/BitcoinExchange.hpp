/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:25:06 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/25 12:53:38 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _exchangeRates;
		bool isValidDate(const std::string& date) const;
		bool isValidValue(const std::string& valueStr, float& value) const;
		float getExchangeRate(const std::string& date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool loadDatabase(const std::string& filename);
		void processInputFile(const std::string& filename);
};

#endif
