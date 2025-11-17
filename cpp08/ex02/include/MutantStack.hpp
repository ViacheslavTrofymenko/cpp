/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:57:01 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/17 12:28:10 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <list>
#include <deque>
#include <iostream>

# define C_GRN   "\001\x1B[32m\002"
# define C_BLU   "\001\x1B[34m\002"
# define C_RED   "\001\x1B[31m\002"
# define C_RESET "\001\x1B[0m\002"

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack const &other);
	MutantStack &operator=(MutantStack const &other);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
};

# include "MutantStack.tpp"
#endif
