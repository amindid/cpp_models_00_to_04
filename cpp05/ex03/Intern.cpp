/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:11:37 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/01 17:36:15 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	// std::cout << "intern default constructor called ." << std::endl;
}

Intern::Intern(const Intern& intern) {
	// std::cout << "intern copy constructor called ." << std::endl;
	(void)intern;
}

Intern::~Intern() {
	// std::cout << "intern destructor called ." << std::endl;
}

Intern& Intern::operator=(const Intern& intern) {
	(void)intern;
	return *this;
}

AForm * Intern::makeForm(std::string formName, std::string formTarget) {
	AForm *(Intern::*forms[3]) (std::string) = {&Intern::makeShrubberyCreation, &Intern::makeRobotomyRequest, &Intern::makePresidentialPardon};
	std::string choices[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++) {
		if (choices[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*forms[i])(formTarget));
		}
	}
	return NULL;
}

AForm * Intern::makeShrubberyCreation(std::string formTarget) {
	return new ShrubberyCreationForm(formTarget);
}

AForm * Intern::makeRobotomyRequest(std::string formTarget) {
	return new RobotomyRequestForm(formTarget);
}
AForm * Intern::makePresidentialPardon(std::string formTarget) {
	return new PresidentialPardonForm(formTarget);
}