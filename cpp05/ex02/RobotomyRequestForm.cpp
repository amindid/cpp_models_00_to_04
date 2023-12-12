/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:32:42 by aouchaad          #+#    #+#             */
/*   Updated: 2023/12/06 12:43:51 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyResquest", 72, 45) {
	// std::cout << "RobotomyRequestForm default constructor called ." << std::endl;
	this->target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyResquest", 72, 45) {
	// std::cout << "RobotomyRequestForm parametrized constructor called ." << std::endl;
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm("RobotomyResquest", 72, 45) {
	// std::cout << "RobotomyRequestForm copy constructor called ." << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	// std::cout << "RobotomyRequestForm destructor called ." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	if (this != &copy)
		this->target = copy.target;
	return *this;
}

std::string RobotomyRequestForm::getTarget(void) {
	return this->target;
}


const char *RobotomyRequestForm::FormNotSignedException::what(void) const throw() {
	return "this Form is not signed yet .";
}

const char *RobotomyRequestForm::ExecutorCantExecuteException::what(void) const throw() {
	return "Too low grade to execute .";
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->signedOrNot()) {
		throw RobotomyRequestForm::FormNotSignedException();
		return;
	}
	if (this->getGradeExecute() < executor.getGrade()) {
		throw RobotomyRequestForm::ExecutorCantExecuteException();
		return;
	}
	if (std::rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "robotomy failed ." << std::endl;
}