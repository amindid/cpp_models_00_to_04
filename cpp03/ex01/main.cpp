/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:37:30 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/19 14:49:09 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
	ScavTrap scavTrap("amine");

	std::cout << scavTrap.getName() << " hit points = " << scavTrap.getHitPoints() << std::endl;
	std::cout << scavTrap.getName() << " energy points = " << scavTrap.getEnergyPoints() << std::endl;
	scavTrap.attack("someone");
	scavTrap.takeDamage(2);
	std::cout << scavTrap.getName() << " hit points = " << scavTrap.getHitPoints() << std::endl;
	std::cout << scavTrap.getName() << " energy points = " << scavTrap.getEnergyPoints() << std::endl;
	scavTrap.beRepaired(2);
	std::cout << scavTrap.getName() << " hit points = " << scavTrap.getHitPoints() << std::endl;
	std::cout << scavTrap.getName() << " energy points = " << scavTrap.getEnergyPoints() << std::endl;
	scavTrap.attack("someone");
	scavTrap.attack("someone");
	scavTrap.attack("someone");
	scavTrap.attack("someone");
	scavTrap.attack("someone");
	scavTrap.attack("someone");
	scavTrap.attack("someone");
	scavTrap.attack("someone");
	scavTrap.attack("someone");
	std::cout << scavTrap.getName() << " hit points = " << scavTrap.getHitPoints() << std::endl;
	std::cout << scavTrap.getName() << " energy points = " << scavTrap.getEnergyPoints() << std::endl;
}