/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:44:08 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/16 12:57:52 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0){}

Point::Point(const Point& copy) : x(copy.x), y(copy.y){
}

Point::Point(const float &a, const float &b) : x(Fixed(a)), y(Fixed(b)) {
}

Point &Point::operator=(const Point& copy){
	(void)copy;
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const{
	return this->x;
}
Fixed Point::getY() const{
	return this->y;
}