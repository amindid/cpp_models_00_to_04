/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:51:16 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/02 13:25:51 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& newWeapon)  : humanAweapon(newWeapon) {
	name = newName;
}

HumanA::~HumanA() {
	
}

void HumanA::attack() {
	
	std::cout << name << " attacks with their " << humanAweapon.getType() << std::endl;
}