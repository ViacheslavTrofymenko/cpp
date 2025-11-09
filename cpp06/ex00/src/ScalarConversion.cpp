/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:04:07 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/09 20:23:37 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConversion.hpp"

bool ScalarConverter::isChar(const std::string &s)
{
	return (s.length() == 3 && s[0] == '\'' && s[2] == '\'' && std::isprint(s[1]));
}
bool ScalarConverter::isInt(const std::string &s)
{
	size_t i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i >= s.size())
		return (false);
	while (i < s.size())
	{
		if (!std::isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

bool ScalarConverter::isFloat(const std::string &s)
{
	size_t i;
	size_t len;
	bool dot;

	if (s == "nanf" || s == "+inff" || s == "-inff")
		return (true);
	dot = false;
	len = s.size();
	if (len < 2 || s[len - 1] != 'f')
		return (false);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (; i < len - 1; i++)
	{
		if (s[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
		else if (!std::isdigit(s[i]))
			return (false);
	}
	return (dot);
}

bool ScalarConverter::isDouble(const std::string &s)
{
	bool dot;
	size_t i;

	if (s == "nan" || s == "+inf" || s == "-inf")
		return (true);
	dot = false;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i >= s.size())
		return (false);
	for (; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
		else if (!std::isdigit(s[i]))
			return (false);
	}
	return (dot);
}

void ScalarConverter::printFromChar(char c)
{
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void ScalarConverter::printFromInt(int n)
{
	if (n < 0 || n > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(n))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(n) << "'\n";

	std::cout << "int: " << n << "\n";
	std::cout << "float: " << static_cast<float>(n) << ".0f\n";
	std::cout << "double: " << static_cast<double>(n) << ".0\n";
}
void ScalarConverter::printFromFloat(float f)
{
	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<int>(f)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(f) << "'\n";

	if (std::isnan(f) || std::isinf(f) || f > INT_MAX || f < INT_MIN)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(f) << "\n";
	if (std::isnan(f))
		std::cout << "float: nanf\n";
	else if (std::isinf(f))
		std::cout << (f > 0 ? "float: +inff\n" : "float: -inff\n");
	else if (f == static_cast<int>(f))
		std::cout << "float: " << f << ".0f\n";
	else
		std::cout << "float: " << f << "f\n";

	double d = static_cast<double>(f);
	if (std::isnan(d))
		std::cout << "double: nan\n";
	else if (std::isinf(d))
		std::cout << (d > 0 ? "double: +inf\n" : "double: -inf\n");
	else if (d == static_cast<int>(d))
		std::cout << "double: " << d << ".0\n";
	else
		std::cout << "double: " << d << "\n";
}

void ScalarConverter::printFromDouble(double d)
{
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d) << "'\n";
	if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";

	if (std::isnan(d))
		std::cout << "float: nanf\n";
	else if (std::isinf(d))
		std::cout << (d > 0 ? "float: +inff\n" : "float: -inff\n");
	else if (d > FLT_MAX || d < -FLT_MAX)
		std::cout << "float: impossible\n";
	else
	{
		float f = static_cast<float>(d);
		if (f == static_cast<int>(f))
			std::cout << "float: " << f << ".0f\n";
		else
			std::cout << "float: " << f << "f\n";
	}
	if (std::isnan(d))
		std::cout << "double: nan\n";
	else if (std::isinf(d))
		std::cout << (d > 0 ? "double: +inf\n" : "double: -inf\n");
	else if (d == static_cast<int>(d))
		std::cout << "double: " << d << ".0\n";
	else
		std::cout << "double: " << d << "\n";
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isChar(literal))
		printFromChar(literal[1]);
	else if (isInt(literal))
	{
		int n = std::atoi(literal.c_str());
		printFromInt(n);
	}
	else if (isFloat(literal))
	{
		float f = std::strtof(literal.c_str(), NULL);
		printFromFloat(f);
	}
	else if (isDouble(literal))
	{
		double d = std::strtod(literal.c_str(), NULL);
		printFromDouble(d);
	}
	else
		std::cout << "Invalid literal" << std::endl;
}
