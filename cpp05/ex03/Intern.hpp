/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:48:47 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/01 17:19:17 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& intern);
		~Intern();
		Intern & operator=(const Intern & intern);
		AForm *makeForm(std::string formName, std::string formTarget);
		AForm *makeShrubberyCreation(std::string formTarget);
		AForm *makeRobotomyRequest(std::string formTarget);
		AForm *makePresidentialPardon(std::string formTarget);
};

#endif