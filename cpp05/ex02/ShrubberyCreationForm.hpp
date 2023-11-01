/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:33:21 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/31 22:16:01 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);

		class FormNotSignedException : public std::exception {
			const char * what() const throw();
		};
		
		class CantOpenFileException : public std::exception {
			const char * what() const throw(); 
		};
		
		class ExecutorCantExecuteException : public std::exception {
			const char * what() const throw();
		};
		
		std::string getTarget(void);
		void execute(Bureaucrat const & executor) const;
};

#endif