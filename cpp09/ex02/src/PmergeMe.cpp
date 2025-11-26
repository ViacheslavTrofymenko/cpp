/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:34:33 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/26 14:39:44 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

double PmergeMe::getTimeInMicroseconds() const
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (double)tv.tv_sec * 1000000.0 + (double)tv.tv_usec;
}

template <typename Container>
void PmergeMe::printSequence(const std::string &prefix, const Container &c) const
{
	std::cout << prefix;
	typename Container::const_iterator it;
	int count = 0;
	for (it = c.begin(); it != c.end() && count < 6; ++it)
	{
		std::cout << *it << " ";
		count++;
	}
	if (c.size() > 6)
	{
		std::cout << "[...] ";
	}
	std::cout << std::endl;
}

void PmergeMe::sortPairs(std::vector<int> &v)
{
	if (v.size() < 2)
		return;
	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		if (v[i] > v[i + 1])
		{
			std::swap(v[i], v[i + 1]);
		}
	}
}

void PmergeMe::merge(std::vector<int> &v, std::vector<int> &left, std::vector<int> &right)
{
	size_t i = 0, j = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
		{
			v.push_back(left[i++]);
		}
		else
		{
			v.push_back(right[j++]);
		}
	}
	while (i < left.size())
		v.push_back(left[i++]);
	while (j < right.size())
		v.push_back(right[j++]);
}

void PmergeMe::mergeSort(std::vector<int> &v)
{
	if (v.size() <= 1)
		return;
	size_t mid = v.size() / 2;
	std::vector<int> left;
	std::vector<int> right;

	for (size_t i = 0; i < mid; ++i)
		left.push_back(v[i]);
	for (size_t i = mid; i < v.size(); ++i)
		right.push_back(v[i]);

	mergeSort(left);
	mergeSort(right);
	v.clear();
	merge(v, left, right);
}

void PmergeMe::insertionSort(std::vector<int> &mainChain, std::vector<int> &pending)
{
	if (pending.empty())
		return;

	if (!mainChain.empty() && !pending.empty())
	{
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pending[0]);
		mainChain.insert(it, pending[0]);
	}

	for (size_t i = 1; i < pending.size(); ++i)
	{
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
		mainChain.insert(it, pending[i]);
	}
}

void PmergeMe::fordJohnsonSort(std::vector<int> &v)
{
	if (v.size() <= 1)
		return;

	int straggler = -1;
	if (v.size() % 2 != 0)
	{
		straggler = v.back();
		v.pop_back();
	}

	sortPairs(v);

	std::vector<int> mainChain;
	std::vector<int> pending;

	for (size_t i = 0; i < v.size(); i += 2)
	{
		pending.push_back(v[i]);
		mainChain.push_back(v[i + 1]);
	}
	mergeSort(mainChain);
	insertionSort(mainChain, pending);

	if (straggler != -1)
	{
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), straggler), straggler);
	}

	v = mainChain;
}

void PmergeMe::fordJohnsonSortList(std::list<int> &l)
{
	l.sort();
}

void PmergeMe::process(int argc, char **argv)
{
	std::vector<int> initialVector;
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		long num;

		if (!(iss >> num) || num <= 0)
		{
			std::cerr << "Error: Invalid input or non-positive number." << std::endl;
			return;
		}
		char remainder;
		if (iss >> remainder)
		{
			std::cerr << "Error: Invalid input format (non-integer or trailing chars)." << std::endl;
			return;
		}
		if (num > 2147483647L)
		{
			std::cerr << "Error: Number too large." << std::endl;
			return;
		}

		initialVector.push_back(static_cast<int>(num));
	}

	if (initialVector.empty())
		return ;
	std::vector<int>	vectorCopy = initialVector;
	std::list<int>		listCopy(initialVector.begin(), initialVector.end());
	printSequence("Before: ", initialVector);

	double startVector = getTimeInMicroseconds();
	fordJohnsonSort(vectorCopy);
	double endVector = getTimeInMicroseconds();
	double timeVector = endVector - startVector;

	double startList = getTimeInMicroseconds();
	fordJohnsonSortList(listCopy);
	double endList = getTimeInMicroseconds();
	double timeList = endList - startList;

	printSequence("After: ", vectorCopy);

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vectorCopy.size()
			  << " elements with std::vector : " << timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << listCopy.size()
			  << " elements with std::list : " << timeList << " us" << std::endl;
}
