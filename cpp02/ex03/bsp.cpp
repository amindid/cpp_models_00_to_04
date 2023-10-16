/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:43:54 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/16 16:52:52 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float distance(Fixed x1, Fixed y1, Fixed x2, Fixed y2) {
	return std::sqrt(std::pow(x2.getRawBits() - x1.getRawBits(), 2) + \
		(std::pow(y2.getRawBits() - y1.getRawBits(), 2)));
}

int pointInEdge(Point const end1, Point const end2, Point const point) {
	float dist1;
	float dist2;
	float edgelength;

	dist1 = distance(point.getX(), point.getY(), end1.getX(), end1.getY());
	dist2 = distance(point.getX(), point.getY(), end2.getX(), end2.getY());
	edgelength = distance(end1.getX(), end1.getY(), end2.getX(), end2.getY());
	
	if (std::abs(dist1 + dist2 - edgelength) < 1e-6)
		return 1;
	return 0;
}

float calculateTriangleArea (Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3) {
	return 0.5 * std::abs(x1.getRawBits() * (y2.getRawBits() - y3.getRawBits()) + x2.getRawBits() * \
	(y3.getRawBits() - y1.getRawBits()) + x3.getRawBits() * (y1.getRawBits() - y2.getRawBits()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	
	float triangleArea;
	float childTriangleA;
	float childTriangleB;
	float childTriangleC;
	BarycentricCoords baryCoords;
	
	if (pointInEdge(a, b, point) || pointInEdge(a, c, point) || pointInEdge(c, b, point))
		return false;
	triangleArea = calculateTriangleArea(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	childTriangleA = calculateTriangleArea(point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	childTriangleB = calculateTriangleArea(point.getX(), point.getY(), b.getX(), b.getY(), a.getX(), a.getY());
	childTriangleC = calculateTriangleArea(point.getX(), point.getY(), c.getX(), c.getY(), a.getX(), a.getY());
	baryCoords.alpha = childTriangleA / triangleArea;
	baryCoords.beta = childTriangleB / triangleArea;
	baryCoords.gama = childTriangleC / triangleArea;
	return baryCoords.alpha >= 0 && baryCoords.beta >= 0 && baryCoords.gama >= 0 && \
						baryCoords.gama + baryCoords.alpha + baryCoords.beta == 1.0;
}