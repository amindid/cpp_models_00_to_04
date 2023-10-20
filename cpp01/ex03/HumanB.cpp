/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:11:16 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/20 10:13:39 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB (std::string newName) {
	name = newName;
	humanBweapon = NULL;
}

HumanB::~HumanB () {
	
}

void HumanB::setWeapon(Weapon& weapon) {
	humanBweapon = &weapon;
}

void HumanB::attack () {
	if (humanBweapon)
		std::cout << name << " attacks with their " << humanBweapon->getType() << std::endl;
}