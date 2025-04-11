/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:09:23 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/17 11:25:43 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	// std::cout << "Default Point constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	// std::cout << "Float Point constructor called" << std::endl;
}

Point::Point(const Point &src) : _x(src.getX()), _y(src.getY())
{
	// std::cout << "Copy Point constructor called" << std::endl;
}

Point::~Point()
{
	// std::cout << "Point destructor called" << std::endl;
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}

/* Point	&Point::operator=(Point const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_x = src.getX();
	this->_y = src.getY();
	return (*this);
} */

std::ostream	&operator<<(std::ostream &out, Point const &value)
{
	out << "Point(" << value.getX() << ", " << value.getY() << ")";
	return out;
}