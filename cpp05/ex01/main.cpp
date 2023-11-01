/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:58:54 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/01 11:37:37 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat brcat1(1, "amine");
	Bureaucrat brcat2(150, "amine");
	Form form1("amineForm", 5 , 5);
	Form form2("amineForm", 5 , 5);
	
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
	std::cout << "--------------------1-------------------" << std::endl;
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
	std::cout << "--------------------2-------------------" << std::endl;
	try {
		form1.beSigned(brcat1);
		brcat1.signForm(form1);
	} catch (const std::exception &exception) {
		std::cerr << "EXCEPTION : " << exception.what() << std::endl;
	}
	std::cout << "--------------------3-------------------" << std::endl;
	try {
		form2.beSigned(brcat2);
	} catch (const std::exception &exception) {
		std::cerr << "EXCEPTION : " << exception.what() << std::endl;
	}
	brcat2.signForm(form2);
	return 0;
}