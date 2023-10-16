/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:01:12 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/14 14:01:27 by aouchaad         ###   ########.fr       */
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
		
		int operator>(const Fixed &copy) const;
		int operator<(const Fixed &copy) const;
		int operator>=(const Fixed &copy) const;
		int operator<=(const Fixed &copy) const;
		int operator==(const Fixed &copy) const;
		int operator!=(const Fixed &copy) const;
		
		Fixed operator+(const Fixed &copy);
		Fixed operator-(const Fixed &copy);
		Fixed operator*(const Fixed &copy);
		Fixed operator/(const Fixed &copy);
		
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		static Fixed& min(Fixed &fixedOne, Fixed &fixedTwo);
		static const Fixed& min(const Fixed &fixedOne, const Fixed &fixedTwo);
		static Fixed& max(Fixed &fixedOne, Fixed &fixedTwo);
		static const Fixed& max(const Fixed &fixedOne, const Fixed &fixedTwo);

};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif