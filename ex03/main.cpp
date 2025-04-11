/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:41:37 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/17 12:13:52 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

# define GREEN "\033[32m"
# define RED "\033[31m"
# define RESET "\033[0m"

void test_point(Point const &a, Point const &b, Point const &c, Point const &p)
{
	std::cout << "Testing point " << p << " with triangle " << a << ", " << b << ", " << c << ": ";
	if (bsp(a, b, c, p))
		std::cout << GREEN << "TRUE" << RESET << std::endl;
	else
		std::cout << RED << "FALSE" << RESET << std::endl;
}

int main(void)
{
	Point a(0, 0);
	Point b(1, 1);
	Point c(0, 2);

	std::cout << std::endl << "Triangle vertices: " << a << ", " << b << ", " << c << std::endl;

	Point inside(0.5, 0.6);
	Point outside(2, 2);
	Point on_edge(0, 1);
	Point very_close_inside(0.5, 0.999);
	Point very_close_outside(0.5, 1.001);
	Point negative(-0.5, -0.5);
	Point float_point(0.1f, 0.1f);

	std::cout << std::endl << "--- Test Points ---" << std::endl << std::endl;

	test_point(a, b, c, inside);
	test_point(a, b, c, outside);
	test_point(a, b, c, on_edge);
	test_point(a, b, c, very_close_inside);
	test_point(a, b, c, very_close_outside);
	test_point(a, b, c, negative);
	test_point(a, b, c, float_point);

	std::cout << std::endl;
	
	return (0);
}