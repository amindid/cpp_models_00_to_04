/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:21:27 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/03 22:23:59 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug () {
	
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << \
	"I love having extra bacon for my7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n\n";
}

void Harl::info () {
	
	std::cout << "[ info ]" << std::endl;
	std::cout << \
	"I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning () {

	std::cout << "[ WARNING ]" << std::endl;
	std::cout << \
	"I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error () {

	std::cout << "[ ERROR ]" << std::endl;
	std::cout <<\
	"This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain (std::string level) {

	void (Harl::*ptr[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = 0;

	while (index < 4)
	{
		if (levels[index] == level)
			break;
		index++;
	}
	if (index < 4)
		(this->*ptr[index]) ();
}