/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:48:57 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/26 13:46:22 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"
#include <sstream>
#include <limits>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

bool RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::applyOperation(char op)
{
	if (_stack.size() < 2)
	{
		throw std::runtime_error("Error: Not enough operands for operation.");
	}
	int	b = _stack.top();
	_stack.pop();
	int	a = _stack.top();
	_stack.pop();
	int	result = 0;
	switch (op)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		if (b == 0)
		{
			_stack.push(a);
			_stack.push(b);
			throw std::runtime_error("Error: Division by zero.");
		}
		result = a / b;
		break;
	}
	_stack.push(result);
}

int RPN::calculate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && isOperator(token[0]))
		{
			try
			{
				applyOperation(token[0]);
			}
			catch (const std::runtime_error &e)
			{
				throw;
			}
		}
		else
		{
			char *endptr;
			long num = std::strtol(token.c_str(), &endptr, 10);
			if (*endptr != '\0' || endptr == token.c_str())
			{
				throw std::runtime_error("Error: Invalid token/expression.");
			}
			if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
			{
				throw std::runtime_error("Error: Number out of integer range.");
			}

			_stack.push(static_cast<int>(num));
		}
	}

	if (_stack.size() != 1)
	{
		throw std::runtime_error("Error: Invalid expression structure (too many operators/operands).");
	}

	return _stack.top();
}
