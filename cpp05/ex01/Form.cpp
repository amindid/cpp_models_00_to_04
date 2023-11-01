/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:47:30 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/28 23:11:29 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeSign(1), _gradeExecute(1){
	// std::cout << "Form default constructor called ." << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExecute) :
_name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute){
	// std::cout << "Form parametrized constructor called ." << std::endl;
	if (this->_gradeSign < 1 || this->_gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& copy) : _name(copy._name), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute) {
	// std::cout << "Form copy constructor called ." << std::endl;
	*this = copy;
}

Form::~Form() {
	// std::cout << "Form destructor called ." << std::endl;
}

Form& Form::operator=(const Form& copy) {
	if (this != &copy)
		this->_signed = copy._signed;
	return *this;
}

const char *Form::GradeTooHighException::what(void) const throw() {
	return "Too high grade value";
}

const char *Form::GradeTooLowException::what(void) const throw() {
	return "Too low grade value";
}

std::string Form::getName(void) const {
	return this->_name;
}

bool Form::signedOrNot(void) const {
	return this->_signed;
}

int Form::getGradeSign(void) const {
	return this->_gradeSign;
}
int Form::getGradeExecute(void) const {
	return this->_gradeExecute;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form name : " << form.getName() << std::endl;
	os << "signed : " << (form.signedOrNot() ? "yes" : "No") << std::endl;
	os << "grade required to sign : " << form.getGradeSign() << std::endl;
	os << "grade required to execute : " << form.getGradeExecute() << std::endl;
	return os;
}

void Form::beSigned(Bureaucrat prcat) {
	if (this->_gradeSign >= prcat.getGrade())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}