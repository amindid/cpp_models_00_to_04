/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:46:04 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/18 15:51:40 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

int main() {
	Point a(2.0f, 2.0f);
	Point b(7.0f, 2.0f);
	Point c(5.0f, 8.0f);
	Point point(4.0f,2.1f);
	if (bsp(a, b, c, point))
		std::cout << "the point is inside the triangle" << std::endl;
	else
		std::cout << "the point is outside the triangle" << std::endl;

	return 0;
}