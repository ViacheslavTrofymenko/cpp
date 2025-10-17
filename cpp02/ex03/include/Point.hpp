/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:55:51 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/17 16:14:55 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
	 Point();
	 Point(float x, float y);
	 Point(const Point& copy);
	 Point& operator=(const Point& other);
	 ~Point();
	 const Fixed	getX( void ) const;
	 const Fixed	getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
