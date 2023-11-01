/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:25:50 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/01 12:57:14 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		bool _signed;
		int const _gradeSign;
		int const _gradeExecute;
	public:
		AForm();
		AForm(const AForm& copy);
		AForm(std::string name, int gradeSign, int gradeExecute);
		virtual ~AForm();
		AForm &operator=(const AForm& copy);

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
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream &os, const AForm& form);

#endif