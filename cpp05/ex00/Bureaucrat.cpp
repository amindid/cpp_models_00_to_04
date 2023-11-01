/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:45:09 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/28 13:09:58 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(1) {
	std::cout << "Bureaucrat default constructor called ." << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : name(name) {
	std::cout << "Bureaucrat parametrized constructor called ." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name){
	std::cout << "Bureaucrat copy constructor called ." << std::endl;
	*this = copy;
}
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called ." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy)
		this->grade = copy.grade;
	return *this;
}

std::string Bureaucrat::getName(void) const {
	return this->name;
}

int Bureaucrat::getGrade(void) const{
	return this->grade;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Too high grade value";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Too low grade value";
}

void Bureaucrat::decrementGrade(void) {
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else 
		this->grade++;
}

void Bureaucrat::incrementGrade(void) {
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}