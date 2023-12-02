/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:13:42 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/21 16:39:19 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
	int size = 100;
	Span test1(size);
	Span test2(size);

	try {
		test1.fillElements(1, 100);
		std::cout << "shortest span " << test1.shortestSpan() << std::endl;
		std::cout << "longest span " << test1.longestSpan() << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << "-----" << i << "-----" << std::endl;
			test2.addNumber(i);
		}
		std::cout << "shortest span " << test2.shortestSpan() << std::endl;
		std::cout << "longest span " << test2.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}