/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:58:54 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/18 13:21:23 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat prcat1(4, "amine");
	// Bureaucrat prcat2(150, "enima");
	// RobotomyRequestForm form1;
	// PresidentialPardonForm form2("frtlan");
	ShrubberyCreationForm form3;

	prcat1.signForm(form3);
	prcat1.executeForm(form3);
	std::cout << "------------------1-------------------" << std::endl;
	// prcat1.signForm(form2);
	// prcat1.executeForm(form2);
	// std::cout << "------------------2-------------------" << std::endl;
	// prcat1.signForm(form3);
	// prcat1.executeForm(form3);
	// std::cout << "/////////////////////////////////////" << std::endl;
	// try {
	// 	prcat2.signForm(form1);
	// } catch (const std::exception & e) {
	// 	std::cerr << "Exception : " << e.what() << std::endl;
	// }
	// std::cout << "-------------------1------------------" << std::endl;
	// try {
	// 	prcat2.executeForm(form1);
	// } catch (const std::exception & e) {
	// 	std::cerr << "Exception : " << e.what() << std::endl;
	// }
	// std::cout << "-------------------2------------------" << std::endl;
	// try {
	// 	prcat2.signForm(form2);
	// } catch (const std::exception & e) {
	// 	std::cerr << "Exception : " << e.what() << std::endl;
	// }
	// std::cout << "-------------------3------------------" << std::endl;
	// try {
	// 	prcat2.executeForm(form2);
	// } catch (const std::exception & e) {
	// 	std::cerr << "Exception : " << e.what() << std::endl;
	// }
	// std::cout << "-------------------4------------------" << std::endl;
	// try {
	// 	prcat2.signForm(form3);
	// } catch (const std::exception & e) {
	// 	std::cerr << "Exception : " << e.what() << std::endl;
	// }
	// std::cout << "-------------------5------------------" << std::endl;
	// try {
	// 	prcat2.executeForm(form3);
	// } catch (const std::exception & e) {
	// 	std::cerr << "Exception : " << e.what() << std::endl;
	// }
	return 0;
}