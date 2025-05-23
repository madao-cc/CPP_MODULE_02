/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:53:55 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/14 11:16:02 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int			_value;
		static const int	bits;
	public:
		// Constructors
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);
		// Destructor
		~Fixed();
		// Overload Operators
		Fixed	&operator=(Fixed const &src);
		// Getter
		int	getRawBits(void) const;
		// Setter
		void	setRawBits(int const raw);
		// Public Methods
		float	toFloat(void) const;
		int	toInt(void) const;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &value);

#endif
