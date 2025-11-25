/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:53:54 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/25 15:47:18 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	if (this != &copy)
	{
		_exchangeRates = copy._exchangeRates;
	}
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this !=&other)
	{
		_exchangeRates = other._exchangeRates;
	}
	return *this;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	int	year;
	int	month;
	int	day;
	char dash1;
	char dash2;
	std::istringstream iss(date);

	if (!(iss >> year >> dash1 >> month >> dash2 >> day))
        return (false);
    if (dash1 != '-' || dash2 != '-')
		return (false);
    if (year < 2009 || year > 2022)
		return (false);
    if (month < 1 || month > 12)
		return (false);
    if (day < 1 || day > 31)
		return (false);
    if (month == 2)
	{
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > 29 || (!isLeap && day > 28))
			return (false);
    } else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
        if (day > 30)
			return (false);
    }

    return (true);
}


bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const
{
    std::istringstream iss(valueStr);

    if (!(iss >> value))
        return (false);
    char remaining;
    if (iss >> remaining)
        return (false);
    if (value < 0)
	{
        std::cerr << "Error: not a positive number." << std::endl;
        return (false);
    }
    if (value > 1000)
	{
        std::cerr << "Error: too large a number." << std::endl;
        return (false);
    }

    return (true);
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return (false);
    std::string line;
    if (!std::getline(file, line))
		return (false);
    while (std::getline(file, line))
	{
        std::string dateStr;
        std::string rateStr;
        size_t commaPos = line.find(',');

        if (commaPos == std::string::npos)
			continue;

        dateStr = line.substr(0, commaPos);
        rateStr = line.substr(commaPos + 1);
        size_t first = rateStr.find_first_not_of(" \t");
        size_t last = rateStr.find_last_not_of(" \t");
        if (first != std::string::npos) {
            rateStr = rateStr.substr(first, (last - first + 1));
        } else {
            rateStr = "";
        }

        float rate;
        std::istringstream iss(rateStr);
        if (iss >> rate) {
            _exchangeRates[dateStr] = rate;
        }
    }

    return !_exchangeRates.empty();
}

float BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
    if (it != _exchangeRates.end() && it->first == date)
        return it->second;

    if (it == _exchangeRates.begin())
        return it->second;
    if (it != _exchangeRates.begin())
        --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
	{
        std::cerr << "Error: could not open file." << std::endl;
        return  ;
    }

    std::string line;
    if (!std::getline(file, line))
		return;
    while (std::getline(file, line))
	{
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
		{
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string dateStr = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);
        size_t first = dateStr.find_first_not_of(" \t");
        if (first != std::string::npos)
			dateStr = dateStr.substr(first);
        size_t last = dateStr.find_last_not_of(" \t");
        if (last != std::string::npos)
			dateStr = dateStr.substr(0, last + 1);

        first = valueStr.find_first_not_of(" \t");
        if (first != std::string::npos)
			valueStr = valueStr.substr(first);
        last = valueStr.find_last_not_of(" \t");
        if (last != std::string::npos)
			valueStr = valueStr.substr(0, last + 1);
        if (!isValidDate(dateStr))
			{
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }
        float value;
        if (!isValidValue(valueStr, value))
		{
            if (value >= 0 && value <= 1000)
			{
                 std::cerr << "Error: bad input => " << line << std::endl;
            }
            continue;
        }
        float rate = getExchangeRate(dateStr);
        float result = value * rate;
        std::cout << dateStr << " => " << value << " = ";
        std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    }
}
