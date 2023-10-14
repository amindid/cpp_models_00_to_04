/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:23:29 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/14 15:21:46 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()  {

	std::cout << "Default constructor called" << std::endl;
	fixedPoint = 0;
}

Fixed::Fixed(const Fixed& copy) {
	
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {

	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &copy)
		this->fixedPoint = copy.getRawBits();

	return *this;
}

Fixed::~Fixed() {
	
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPoint;
}

void Fixed::setRawBits(int const raw) {

	fixedPoint = raw;
}