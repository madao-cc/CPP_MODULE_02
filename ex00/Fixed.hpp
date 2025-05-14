/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:53:55 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/14 11:09:28 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int			value;
		static const int	bits;
	public:
		// Constructors
		Fixed();
		// Copy constructor
		Fixed(const Fixed &src);
		// Destructor
		~Fixed();
		// Assignment operator
		Fixed	&operator=(const Fixed &src);
		// Member functions
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
