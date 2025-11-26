/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:30:25 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/26 14:35:42 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <sys/time.h>
#include <cmath>
#include <iomanip>
#include <list>

template <typename T>
struct Pair
{
	T first;
	T second;
};

class PmergeMe
{
private:
	double	getTimeInMicroseconds() const;
	void	sortPairs(std::vector<int> &v);
	void	merge(std::vector<int> &v, std::vector<int> &left, std::vector<int> &right);
	void	mergeSort(std::vector<int> &v);
	void	insertionSort(std::vector<int> &mainChain, std::vector<int> &pending);
	void	fordJohnsonSort(std::vector<int> &v);
	void	fordJohnsonSortList(std::list<int> &l);

	template <typename Container>
	void	printSequence(const std::string &prefix, const Container &c) const;

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	void	process(int argc, char **argv);
};

#endif
