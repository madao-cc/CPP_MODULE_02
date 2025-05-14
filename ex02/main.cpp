/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:41:37 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/14 15:47:43 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/* int	main(void)
{
	Fixed	a;
	Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
} */

int main(void)
{
	// ANSI color codes
	const std::string GREEN  = "\033[32m";
	const std::string YELLOW = "\033[33m";
	const std::string RESET  = "\033[0m";
	std::cout << std::boolalpha;

	// Constructors
	Fixed a;                     // default
	Fixed b(10);                // int
	Fixed c(42.42f);            // float
	Fixed f(5.05f);             // float
	Fixed d(b);                 // copy
	Fixed z(0);			 // int

	std::cout << "-- Constructor Outputs --" << std::endl;
	std::cout << GREEN << "a (default): " << a << RESET << "   " << YELLOW << "Expected: 0" << RESET << std::endl;
	std::cout << GREEN << "b (10):      " << b << RESET << "   " << YELLOW << "Expected: 10" << RESET << std::endl;
	std::cout << GREEN << "c (42.42f):  " << c << RESET << "   " << YELLOW << "Expected: 42.4219" << RESET << std::endl;
	std::cout << GREEN << "d (copy b):  " << d << RESET << "   " << YELLOW << "Expected: 10" << RESET << std::endl << std::endl;

	// Comparison operators
	std::cout << "-- Comparison Tests --" << std::endl;
	std::cout << GREEN << "b > a: " << (b > a) << RESET << "   " << YELLOW << "Expected: true" << RESET << std::endl;
	std::cout << GREEN << "b < a: " << (b < a) << RESET << "   " << YELLOW << "Expected: false" << RESET << std::endl;
	std::cout << GREEN << "b < c: " << (b < c) << RESET << "   " << YELLOW << "Expected: true" << RESET << std::endl;
	std::cout << GREEN << "b >= d: " << (b >= d) << RESET << "   " << YELLOW << "Expected: true" << RESET << std::endl;
	std::cout << GREEN << "a <= d: " << (a <= d) << RESET << "   " << YELLOW << "Expected: true" << RESET << std::endl;
	std::cout << GREEN << "b == d: " << (b == d) << RESET << "   " << YELLOW << "Expected: true" << RESET << std::endl;
	std::cout << GREEN << "b != d: " << (b != d) << RESET << "   " << YELLOW << "Expected: false" << RESET << std::endl;
	std::cout << GREEN << "b != c: " << (b != c) << RESET << "   " << YELLOW << "Expected: true" << RESET << std::endl << std::endl;

	// Arithmetic operators
	std::cout << "-- Arithmetic Tests --" << std::endl;
	Fixed sum  = b + c;
	Fixed sum2 = c + f;
	Fixed diff = c - b;
	Fixed prod = b * c;
	Fixed quot = c / b;
	std::cout << GREEN << "b + c = " << sum << RESET << "   " << YELLOW << "Expected: 52.4219" << RESET << std::endl;
	std::cout << GREEN << "c + f = " << sum2 << RESET << "   " << YELLOW << "Expected: 47.4719" << RESET << std::endl;
	std::cout << GREEN << "c - b = " << diff << RESET << "   " << YELLOW << "Expected: 32.4219" << RESET << std::endl;
	std::cout << GREEN << "b * c = " << prod << RESET << "   " << YELLOW << "Expected: 424.219" << RESET << std::endl;
	std::cout << GREEN << "c / b = " << quot << RESET << "   " << YELLOW << "Expected: 4.24219" << RESET << std::endl << std::endl;
	std::cout << GREEN << "b / z = " << (b / z) << RESET << "   " << YELLOW << "Expected: Undefined Behaviour" << RESET << std::endl;

	// Increment / Decrement
	std::cout << "-- Increment/Decrement Tests --" << std::endl;
	Fixed e;
	std::cout << GREEN << "Initial e = " << e << RESET << "   " << YELLOW << "Expected: 0" << RESET << std::endl;
	Fixed preInc = ++e;
	std::cout << GREEN << "++e    = " << preInc << RESET << "   " << YELLOW << "Expected: 0.00390625" << RESET << std::endl;
	std::cout << GREEN << "e      = " << e << RESET << "   " << YELLOW << "Expected: 0.00390625" << RESET << std::endl;
	Fixed postInc = e++;
	std::cout << GREEN << "e++    = " << postInc << RESET << "   " << YELLOW << "Expected: 0.00390625" << RESET << std::endl;
	std::cout << GREEN << "e      = " << e << RESET << "   " << YELLOW << "Expected: 0.0078125" << RESET << std::endl;
	Fixed preDec = --e;
	std::cout << GREEN << "--e    = " << preDec << RESET << "   " << YELLOW << "Expected: 0.00390625" << RESET << std::endl;
	std::cout << GREEN << "e      = " << e << RESET << "   " << YELLOW << "Expected: 0.00390625" << RESET << std::endl;
	Fixed postDec = e--;
	std::cout << GREEN << "e--    = " << postDec << RESET << "   " << YELLOW << "Expected: 0.00390625" << RESET << std::endl;
	std::cout << GREEN << "e      = " << e << RESET << "   " << YELLOW << "Expected: 0" << RESET << std::endl << std::endl;
	
	// Min / Max
	std::cout << "-- Min/Max Tests --" << std::endl;
	std::cout << GREEN << "min(b, c) = " << Fixed::min(b, c) << RESET << "   " << YELLOW << "Expected: 10" << RESET << std::endl;
	std::cout << GREEN << "max(b, c) = " << Fixed::max(b, c) << RESET << "   " << YELLOW << "Expected: 42.4219" << RESET << std::endl;
	const Fixed cb(5.05f);
	const Fixed cc(2.02f);
	std::cout << GREEN << "min(const cb, cc) = " << Fixed::min(cb, cc) << RESET << "   " << YELLOW << "Expected: 2.01953" << RESET << std::endl;
	std::cout << GREEN << "max(const cb, cc) = " << Fixed::max(cb, cc) << RESET << "   " << YELLOW << "Expected: 5.05078" << RESET << std::endl;
	
	// Non-const tests
	Fixed l(10);
	Fixed m(20);
	std::cout << "-- Non-const Min/Max Tests --" << std::endl;
	std::cout << GREEN << "Testing non-const min and max:" << RESET << std::endl;
	Fixed &minResult = Fixed::min(l, m);
	std::cout << GREEN << "min(l, m): " << minResult << RESET << "   " << YELLOW << "(Expected: 10)" << RESET << std::endl;
	minResult = Fixed(5);
	std::cout << GREEN << "After modifying minResult: l = " << l << ", m = " << m << RESET << "   " << YELLOW << "(Expected: l = 5, m = 20)" << RESET << std::endl;
	Fixed &maxResult = Fixed::max(l, m);
	std::cout << GREEN << "max(l, m): " << maxResult << RESET << "   " << YELLOW << "(Expected: 20)" << RESET << std::endl;
	maxResult = Fixed(25);
	std::cout << GREEN << "After modifying maxResult: l = " << l << ", m = " << m << RESET << "   " << YELLOW << "(Expected: l = 5, m = 25)" << RESET << std::endl << std::endl;

	// Const tests
	const Fixed n(15);
	const Fixed o(30);
	std::cout << "-- Const Min/Max Tests --" << std::endl;
	std::cout << GREEN << "Testing const min and max:" << RESET << std::endl;
	const Fixed &constMinResult = Fixed::min(n, o);
	std::cout << GREEN << "min(n, o): " << constMinResult << RESET << "   " << YELLOW << "(Expected: 15)" << RESET << std::endl;
	const Fixed &constMaxResult = Fixed::max(n, o);
	std::cout << GREEN << "max(n, o): " << constMaxResult << RESET << "   " << YELLOW << "(Expected: 30)" << RESET << std::endl << std::endl;

	// Mixed const and non-const tests
	Fixed p(50);
	const Fixed q(40);
	std::cout << "-- Mixed Const/Non-const Min/Max Tests --" << std::endl;
	std::cout << GREEN << "Testing mixed const and non-const min and max:" << RESET << std::endl;
	const Fixed &mixedMinResult = Fixed::min(p, q);
	std::cout << GREEN << "min(p, q): " << mixedMinResult << RESET << "   " << YELLOW << "(Expected: 40)" << RESET << std::endl;
	const Fixed &mixedMaxResult = Fixed::max(p, q);
	std::cout << GREEN << "max(p, q): " << mixedMaxResult << RESET << "   " << YELLOW << "(Expected: 50)" << RESET << std::endl << std::endl;

	return (0);
}
