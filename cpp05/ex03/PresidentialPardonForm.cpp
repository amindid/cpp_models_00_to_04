/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:22:08 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/01 11:08:52 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5) {
	// std::cout << "PresidentialPardonForm default constructor called ." << std::endl;
	this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5) {
	// std::cout << "PresidentialPardonForm parametrized constructor called ." << std::endl;
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm("PresidentialPardon", 25, 5){
	// std::cout << "PresidentialPardonForm copy constructor called ." << std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	// std::cout << "PresidentialPardonForm destructor called ." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	if (this != &copy)
		this->target = copy.target;
	return *this;
}

std::string PresidentialPardonForm::getTarget(void) {
	return this->target;
}

const char *PresidentialPardonForm::FormNotSignedException::what(void) const throw() {
	return "this Form is not signed yet .";
}

const char *PresidentialPardonForm::ExecutorCantExecuteException::what(void) const throw() {
	return "Too low grade to execute .";
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->signedOrNot()) {
		throw PresidentialPardonForm::FormNotSignedException();
		return;
	}
	if (this->getGradeExecute() < executor.getGrade()) {
		throw PresidentialPardonForm::ExecutorCantExecuteException();
		return;
	}
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}