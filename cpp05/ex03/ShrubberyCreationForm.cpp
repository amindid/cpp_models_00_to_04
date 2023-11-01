/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:33:17 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/01 11:11:46 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137) {
	// std::cout << "ShrubberyCreationForm default constructor called ." << std::endl;
	this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137) {
	// std::cout << "ShrubberyCreationForm parametrized constructor called ." << std::endl;
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm("ShrubberyCreation", 145, 137) {
	// std::cout << "ShrubberyCreationForm copy constructor called ." << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	// std::cout << "ShrubberyCreationForm destructor called ." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	if (this != &copy)
		this->target = copy.target;
	return *this;
}

std::string ShrubberyCreationForm::getTarget(void) {
	return this->target;
}

const char *ShrubberyCreationForm::FormNotSignedException::what(void) const throw() {
	return "this Form is not signed yet .";
}

const char *ShrubberyCreationForm::ExecutorCantExecuteException::what(void) const throw() {
	return "Too low grade to execute .";
}

const char *ShrubberyCreationForm::CantOpenFileException::what(void) const throw() {
	return "cant open the file .";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!this->signedOrNot()) {
		throw ShrubberyCreationForm::FormNotSignedException();
		return;
	}
	if (this->getGradeExecute() < executor.getGrade()) {
		throw ShrubberyCreationForm::ExecutorCantExecuteException();
		return;
	}
	std::ofstream outPutFile(this->target + "_shrubbery");
	if (!outPutFile) {
		throw ShrubberyCreationForm::CantOpenFileException();
		return;
	}

	outPutFile << "                                                         .\n"
			   << "                                              .         ;  \n"
			   << "                 .              .              ;%     ;;   \n"
			   << "                   ,           ,                :;%  %;   \n"
			   << "                    :         ;                   :;%;'     .,   \n"
			   << "           ,.        %;     %;            ;        %;'    ,;\n"
			   << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
			   << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
			   << "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
			   << "                `%;.     ;%;     %;'         `;%%;.%;'\n"
			   << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
			   << "                    `:%;.  :;bd%;          %;@%;'\n"
			   << "                      `@%:.  :;%.         ;@@%;'   \n"
			   << "                        `@%.  `;@%.      ;@@%;         \n"
			   << "                          `@%%. `@%%    ;@@%;        \n"
			   << "                            ;@%. :@%%  %@@%;       \n"
			   << "                              %@bd%%%bd%%:;     \n"
			   << "                                #@%%%%%:;;\n"
			   << "                                %@@%%%::;\n"
			   << "                                %@@@%(o);  . '         \n"
			   << "                                %@@@o%;:(.,'         \n"
			   << "                            `.. %@@@o%::;         \n"
			   << "                               `)@@@o%::;         \n"
			   << "                                %@@(o)::;        \n"
			   << "                               .%@@@@%::;         \n"
			   << "                               ;%@@@@%::;.          \n"
			   << "                              ;%@@@@%%:;;;. \n"
			   << "                          ...;%@@@@@%%:;;;;,..    \n";
}