/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:37:30 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/19 08:53:59 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clapTrap("amine");

	std::cout << clapTrap.getName() << " hit points = " << clapTrap.getHitPoints() << std::endl;
	std::cout << clapTrap.getName() << " energy points = " << clapTrap.getEnergyPoints() << std::endl;
	clapTrap.attack("someone");
	clapTrap.takeDamage(2);
	std::cout << clapTrap.getName() << " hit points = " << clapTrap.getHitPoints() << std::endl;
	std::cout << clapTrap.getName() << " energy points = " << clapTrap.getEnergyPoints() << std::endl;
	clapTrap.beRepaired(2);
	std::cout << clapTrap.getName() << " hit points = " << clapTrap.getHitPoints() << std::endl;
	std::cout << clapTrap.getName() << " energy points = " << clapTrap.getEnergyPoints() << std::endl;
	clapTrap.attack("someone");
	clapTrap.attack("someone");
	clapTrap.attack("someone");
	clapTrap.attack("someone");
	clapTrap.attack("someone");
	clapTrap.attack("someone");
	clapTrap.attack("someone");
	clapTrap.attack("someone");
	clapTrap.attack("someone");
	std::cout << clapTrap.getName() << " hit points = " << clapTrap.getHitPoints() << std::endl;
	std::cout << clapTrap.getName() << " energy points = " << clapTrap.getEnergyPoints() << std::endl;
}