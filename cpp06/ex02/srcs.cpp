/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:25:28 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/11 11:55:59 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.hpp"

Base* generate(void) {
	
	std::srand(time(NULL));
	int random = std::rand() % 3;
	
	switch (random) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return nullptr;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown type." << std::endl;
}

void identify(Base& p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (const std::bad_cast &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		} catch (const std::bad_cast &e) {
			try {
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			} catch (const std::bad_cast &e) {
				std::cout << "unknown type" << std::endl;
			}
		}
	}
}