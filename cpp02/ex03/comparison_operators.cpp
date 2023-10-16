/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison_operators.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:44:00 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/15 17:44:02 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::operator>(const Fixed &copy) const {
	  return this->fixedPoint > copy.fixedPoint;
}

int Fixed::operator<(const Fixed &copy) const {
	return this->fixedPoint < copy.fixedPoint;
}

int Fixed::operator>=(const Fixed &copy) const {
	return this->fixedPoint >= copy.fixedPoint;
}

int Fixed::operator<=(const Fixed &copy) const {
	return this->fixedPoint <= copy.fixedPoint;
}

int Fixed::operator==(const Fixed &copy) const {
	return this->fixedPoint == copy.fixedPoint;
}

int Fixed::operator!=(const Fixed &copy) const {
	return this->fixedPoint != copy.fixedPoint;
}