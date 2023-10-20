/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:37:30 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/20 11:12:03 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap diamondTrap("amine");

	std::cout << diamondTrap.getDiamondName() << " hit points = " << diamondTrap.getHitPoints() << std::endl;
	std::cout << diamondTrap.getDiamondName() << " energy points = " << diamondTrap.getEnergyPoints() << std::endl;
	diamondTrap.attack("someone");
	diamondTrap.takeDamage(2);
	std::cout << diamondTrap.getDiamondName() << " hit points = " << diamondTrap.getHitPoints() << std::endl;
	std::cout << diamondTrap.getDiamondName() << " energy points = " << diamondTrap.getEnergyPoints() << std::endl;
	diamondTrap.beRepaired(2);
	std::cout << diamondTrap.getDiamondName() << " hit points = " << diamondTrap.getHitPoints() << std::endl;
	std::cout << diamondTrap.getDiamondName() << " energy points = " << diamondTrap.getEnergyPoints() << std::endl;
	diamondTrap.attack("someone");
	diamondTrap.attack("someone");
	diamondTrap.attack("someone");
	diamondTrap.attack("someone");
	diamondTrap.attack("someone");
	diamondTrap.attack("someone");
	diamondTrap.attack("someone");
	diamondTrap.attack("someone");
	diamondTrap.attack("someone");
	std::cout << diamondTrap.getDiamondName() << " hit points = " << diamondTrap.getHitPoints() << std::endl;
	std::cout << diamondTrap.getDiamondName() << " energy points = " << diamondTrap.getEnergyPoints() << std::endl;
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();
}