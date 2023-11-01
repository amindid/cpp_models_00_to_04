/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:25:50 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/28 22:54:36 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const _name;
		bool _signed;
		int const _gradeSign;
		int const _gradeExecute;
	public:
		Form();
		Form(const Form& copy);
		Form(std::string name, int gradeSign, int gradeExecute);
		~Form();
		Form &operator=(const Form& copy);

		class GradeTooHighException : public std::exception {
			public:
				const char * what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw();
		};

		std::string getName(void) const;
		bool signedOrNot(void) const;
		int getGradeSign(void) const;
		int getGradeExecute(void) const;

		void beSigned(Bureaucrat prcat);
};

std::ostream& operator<<(std::ostream &os, const Form& form);

#endif