/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:31:27 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/17 17:01:56 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

static float triangleArea(Point const& a, Point const& b, Point const& c)
{
	return 0.5f * std::abs(
		(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
		b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
		c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))
	);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float total = triangleArea(a, b, c);
	float t1 = triangleArea(point, b, c);
	float t2 = triangleArea(a, point, c);
	float t3 = triangleArea(a, b, point);

	if (t1 == 0 || t2 == 0 || t3 == 0)
		return false;

	return (std::abs((t1 + t2 + t3) - total) < 0.0001f);
}
