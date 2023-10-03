/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:24:37 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/03 22:42:13 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {

	Harl harl;
	
	if (ac != 2) {

		std::cout << "invalid arguments" << std::endl;
		exit (1);
	}
	
	std::string level = std::string(av[1]);
	std::string choices[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int choice;
	
	for (int i = 0; i < 4; i++) {
		
		if (choices[i] == level)
			choice = i + 1;
	}
	
	switch (choice) {
		
		case 1:
			for (int i = 0; i < 4; i++)
				harl.complain(choices[i]);
			break;
		case 2:
			for (int i = 1; i < 4; i++)
				harl.complain(choices[i]);
			break;
		case 3:
			for (int i = 2; i < 4; i++)
				harl.complain(choices[i]);
			break;
		case 4:
				harl.complain(choices[3]);
			break;
		
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}