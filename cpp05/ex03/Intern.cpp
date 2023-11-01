/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:11:37 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/01 13:14:47 by aouchaad         ###   ########.fr       */
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
	AForm *forms[3] = {new ShrubberyCreationForm(formTarget), new RobotomyRequestForm(formTarget), new PresidentialPardonForm(formTarget)};
	std::string choices[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++) {
		if (choices[i] == formName) {
			for (int j = i + 1; j < 3; j++)
				delete forms[j];
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i];
		}
		delete forms[i];
	}
	return NULL;
}