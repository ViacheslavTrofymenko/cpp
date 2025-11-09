/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:53:48 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/09 16:58:52 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cfloat>

class ScalarConverter
{
	public:
		static void convert(const std::string &literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		static bool isChar(const std::string &s);
		static bool isInt(const std::string &s);
		static bool isFloat(const std::string &s);
		static bool isDouble(const std::string &s);

		static void printFromChar(char c);
		static void printFromInt(int n);
		static void printFromFloat(float f);
		static void printFromDouble(double d);
};
