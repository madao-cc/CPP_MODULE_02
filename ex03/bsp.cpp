/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:59:40 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/17 12:01:21 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const _point)
{
	Fixed	abc = get_area(a, b, c);
	Fixed	abp = get_area(a, b, _point);
	Fixed	acp = get_area(a, c, _point);
	Fixed	bcp = get_area(b, c, _point);

	if (abp == 0 || acp == 0 || bcp == 0)
		return (false);
	else if (abc == abp + acp + bcp)
		return (true);
	return (false);
}

Fixed	get_area(Point const a, Point const b, Point const c)
{
	Fixed	area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
	if (area < 0)
		area = area * -1;
	area = area / 2;
	return (area);
}