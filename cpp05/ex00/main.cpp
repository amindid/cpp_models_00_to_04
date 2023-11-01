/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:58:54 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/01 11:36:13 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat brcat1(1, "amine");
	Bureaucrat brcat2(150, "amine");
	try {
		brcat1.incrementGrade();
	} catch (const std::exception &exception) {
		std::cerr << "EXCEPTION : " << exception.what() << std::endl;
	}
	try {
		brcat2.decrementGrade();
	} catch (const std::exception &exception) {
		std::cerr << "EXCEPTION : " << exception.what() << std::endl;
	}
	std::cout << "---------------------------------------" << std::endl;
	try {
		brcat1.decrementGrade();
	} catch (const std::exception &exception) {
		std::cerr << "EXCEPTION : " << exception.what() << std::endl;
	}
	try {
		brcat2.incrementGrade();
	} catch (const std::exception &exception) {
		std::cerr << "EXCEPTION : " << exception.what() << std::endl;
	}
	return 0;
}