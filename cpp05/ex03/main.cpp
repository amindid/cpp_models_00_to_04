/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:58:54 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/01 13:25:56 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

void _main(void) {
	Intern someRandomIntern;
	Bureaucrat prcat(1, "amine");
	AForm* rrf;
	
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	if (!rrf) {
		std::cerr << "form name does not exist ." << std::endl;
		return;
	}
	try {
		rrf->beSigned(prcat);
		prcat.executeForm(*rrf);
	} catch (const std::exception &e) {
		std::cerr << "Exeption : " << e.what() << std::endl;
	}
	delete rrf;
}

int main(void) {
	_main();
	std::cout << "---------------------------------" << std::endl;
	system("leaks Bureaucrat");
	return 0;
}