/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:31:59 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/28 13:09:54 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
		private:
			std::string const name;
			int grade;
		public:
			Bureaucrat();
			Bureaucrat(int grade, std::string name);
			Bureaucrat(const Bureaucrat &copy);
			~Bureaucrat();
			Bureaucrat &operator=(const Bureaucrat &copy);
			
			class GradeTooHighException : public std::exception {
				public:
					const char* what(void) const throw();
			};
			
			class GradeTooLowException : public std::exception {
				public:
					const char* what(void) const throw();
			};

			std::string getName(void) const ;
			int getGrade(void) const;
			void incrementGrade(void);
			void decrementGrade(void);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif