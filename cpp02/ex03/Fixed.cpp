/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:23:29 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/16 11:57:05 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()  {
	fixedPoint = 0;
}

Fixed::Fixed(const Fixed& copy) {
	*this = copy;
}

Fixed::Fixed(const int intValue) {
	fixedPoint = (intValue << numbits);
}

Fixed::Fixed(const float floatValue) {
	fixedPoint = roundf(floatValue * (1 << numbits));
}

Fixed &Fixed::operator=(const Fixed &copy) {
	if(this != &copy)
		this->fixedPoint = copy.getRawBits();

	return *this;
}

float Fixed::toFloat(void) const {
	return (float)(fixedPoint) / (1 << numbits);
}

int Fixed::toInt(void) const {
	return fixedPoint >> numbits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
	return fixedPoint;
}

void Fixed::setRawBits(int const raw) {
	fixedPoint = raw;
}

Fixed& Fixed::min(Fixed &fixedOne, Fixed &fixedTwo) {
	return fixedOne < fixedTwo ? fixedOne : fixedTwo;
}

const Fixed& Fixed::min(const Fixed &fixedOne, const Fixed &fixedTwo) {
	return fixedOne < fixedTwo ? fixedOne : fixedTwo;
}

const Fixed& Fixed::max(const Fixed &fixedOne, const Fixed &fixedTwo) {
	return fixedOne > fixedTwo ? fixedOne : fixedTwo;
}

Fixed& Fixed::max(Fixed &fixedOne, Fixed &fixedTwo) {
	return fixedOne > fixedTwo ? fixedOne : fixedTwo;
}