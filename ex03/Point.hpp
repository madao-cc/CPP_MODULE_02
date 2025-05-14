/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:48:01 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/14 12:39:01 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		// Constructors
		Point();
		Point(const float x, const float y);
		// Copy Constructor
		Point(const Point &src);
		// Destructor
		~Point();
		// Overload Operators
		Point	&operator=(Point const &src);
		// Getter
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

std::ostream	&operator<<(std::ostream &out, Point const &value);
Fixed	get_area(Point const a, Point const b, Point const c);
bool		bsp(Point const a, Point const b, Point const c, Point const _point);

#endif