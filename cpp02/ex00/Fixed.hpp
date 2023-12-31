/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:01:12 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/09 12:46:40 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	
	private:
		int	fixedPoint;
		static const int numbits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed &operator=(const Fixed &copy);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif