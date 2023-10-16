/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_operators.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:43:48 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/15 17:43:51 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed Fixed::operator+(const Fixed &copy) {
	return Fixed(toFloat() + copy.toFloat());
}

Fixed Fixed::operator-(const Fixed &copy) {
	return Fixed(toFloat() - copy.toFloat());
}

Fixed Fixed::operator*(const Fixed &copy) {
	return Fixed(toFloat() * copy.toFloat());
}

Fixed Fixed::operator/(const Fixed &copy) {
	return Fixed(toFloat() / copy.toFloat());
}

Fixed &Fixed::operator++(void){
	this->fixedPoint += 1;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp = *this;
	this->fixedPoint += 1;
	return tmp;
}

Fixed &Fixed::operator--(void){
	this->fixedPoint -= 1;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed tmp = *this;
	this->fixedPoint -= 1;
	return tmp;
}