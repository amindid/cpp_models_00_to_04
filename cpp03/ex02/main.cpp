/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:37:30 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/19 13:53:19 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
	FragTrap fragTrap("amine");

	std::cout << fragTrap.getName() << " hit points = " << fragTrap.getHitPoints() << std::endl;
	std::cout << fragTrap.getName() << " energy points = " << fragTrap.getEnergyPoints() << std::endl;
	fragTrap.attack("someone");
	fragTrap.takeDamage(2);
	std::cout << fragTrap.getName() << " hit points = " << fragTrap.getHitPoints() << std::endl;
	std::cout << fragTrap.getName() << " energy points = " << fragTrap.getEnergyPoints() << std::endl;
	fragTrap.beRepaired(2);
	std::cout << fragTrap.getName() << " hit points = " << fragTrap.getHitPoints() << std::endl;
	std::cout << fragTrap.getName() << " energy points = " << fragTrap.getEnergyPoints() << std::endl;
	fragTrap.attack("someone");
	fragTrap.attack("someone");
	fragTrap.attack("someone");
	fragTrap.attack("someone");
	fragTrap.attack("someone");
	fragTrap.attack("someone");
	fragTrap.attack("someone");
	fragTrap.attack("someone");
	fragTrap.attack("someone");
	std::cout << fragTrap.getName() << " hit points = " << fragTrap.getHitPoints() << std::endl;
	std::cout << fragTrap.getName() << " energy points = " << fragTrap.getEnergyPoints() << std::endl;
	fragTrap.highFivesGuys();
}