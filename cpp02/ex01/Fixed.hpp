/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:01:12 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/14 15:15:18 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	
	private:
		int	fixedPoint;
		static const int numbits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed &operator=(const Fixed &copy);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif