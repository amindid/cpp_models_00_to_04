/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:47:30 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/28 23:24:16 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeSign(1), _gradeExecute(1){
	// std::cout << "AForm default constructor called ." << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExecute) :
_name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute){
	// std::cout << "AForm parametrized constructor called ." << std::endl;
	if (this->_gradeSign < 1 || this->_gradeExecute < 1)
		throw AForm::GradeTooHighException();
	else if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute) {
	// std::cout << "AForm copy constructor called ." << std::endl;
	*this = copy;
}

AForm::~AForm() {
	// std::cout << "AForm destructor called ." << std::endl;
}

AForm& AForm::operator=(const AForm& copy) {
	if (this != &copy)
		this->_signed = copy._signed;
	return *this;
}

const char *AForm::GradeTooHighException::what(void) const throw() {
	return "Too high grade value";
}

const char *AForm::GradeTooLowException::what(void) const throw() {
	return "Too low grade value";
}

std::string AForm::getName(void) const {
	return this->_name;
}

bool AForm::signedOrNot(void) const {
	return this->_signed;
}

int AForm::getGradeSign(void) const {
	return this->_gradeSign;
}
int AForm::getGradeExecute(void) const {
	return this->_gradeExecute;
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform) {
	os << "AForm name : " << Aform.getName() << std::endl;
	os << "signed : " << (Aform.signedOrNot() ? "yes" : "No") << std::endl;
	os << "grade required to sign : " << Aform.getGradeSign() << std::endl;
	os << "grade required to execute : " << Aform.getGradeExecute() << std::endl;
	return os;
}

void AForm::beSigned(Bureaucrat prcat) {
	if (this->_gradeSign >= prcat.getGrade())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}