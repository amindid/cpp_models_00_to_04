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