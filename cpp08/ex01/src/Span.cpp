/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:41:12 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/15 17:31:02 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <limits.h>

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &copy) : N(copy.N), numbers(copy.numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		numbers = other.numbers;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int num)
{
	if (numbers.size() >= N)
	{
		throw std::out_of_range("Cannot add number, Span is full");
	}
	numbers.push_back(num);
}

void Span::addNumbers(int *begin, int *end)
{
	size_t to_add = std::distance(begin, end);
	if (numbers.size() + to_add > N)
	{
		throw std::out_of_range("Cannot add more numbers, Span is full");
	}
	while (begin != end)
	{
		numbers.push_back(*begin);
		++begin;
	}
}

int Span::shortestSpan()
{
	if (numbers.size() < 2)
	{
		throw std::logic_error("Cannot find span, not enough numbers");
	}

	std::sort(numbers.begin(), numbers.end());

	int minSpan = INT_MAX;
	for (size_t i = 0; i < numbers.size() - 1; ++i)
	{
		int span = numbers[i + 1] - numbers[i];
		if (span < minSpan)
		{
			minSpan = span;
		}
	}
	return minSpan;
}

int Span::longestSpan()
{
	if (numbers.size() < 2)
	{
		throw std::logic_error("Cannot find span, not enough numbers");
	}

	int maxNum = numbers[0];
	int minNum = numbers[0];

	for (size_t i = 1; i < numbers.size(); ++i)
	{
		if (numbers[i] > maxNum)
		{
			maxNum = numbers[i];
		}
		if (numbers[i] < minNum)
		{
			minNum = numbers[i];
		}
	}
	return (maxNum - minNum);
}
