/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:53:34 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/31 22:45:08 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);

		class FormNotSignedException : public std::exception {
			const char * what() const throw();
		};
		
		class ExecutorCantExecuteException : public std::exception {
			const char * what() const throw(); 
		};
		
		std::string getTarget(void);
		void execute(Bureaucrat const & executor) const;
};

#endif