/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:43:39 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/16 14:01:40 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

typedef struct BarycentricCoords {
	float alpha;
	float beta;
	float gama;
} BarycentricCoords;

class Point {
	
	private:
		const Fixed x; 
		const Fixed y;
	public:
		Point();
		Point(const float &a, const float &b);
		Point(const Point& copy);
		Point &operator=(const Point& copy);
		~Point();
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif