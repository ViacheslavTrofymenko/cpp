/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:29:15 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/12 19:39:13 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include "Array.hpp"

template <class T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <class T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n)
{
	if (n > 0)
		_data = new T[n]();
}

template <class T>
Array<T>::Array(const Array &other) : _data(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		if (_size > 0)
		{
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}
		else
		{
			_data = NULL;
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _data[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
