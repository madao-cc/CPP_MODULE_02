/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:53:55 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/13 16:06:47 by mikelitoris      ###   ########.fr       */
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
		Fixed();
		Fixed(const Fixed &src);
		~Fixed();
		Fixed	&operator=(const Fixed &src);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
