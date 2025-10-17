/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:05:17 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/17 16:53:25 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point(void): x(0), y(0) {}

Point::Point(float a, float b): x(a), y(b) {}

Point::Point(const Point& other): x(other.getX()), y(other.getY()) {}

Point&	Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

Point::~Point(void) {}

const Fixed Point::getX(void) const
{
	return this->x;
}

const Fixed Point::getY(void) const
{
	return this->y;
}
