/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:35:08 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/15 17:20:38 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
	private:
		unsigned int N;
		std::vector<int> numbers;

	public:
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int num);
		void addNumbers(int *begin, int *end);
		int shortestSpan();
		int longestSpan();
};

#endif
