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