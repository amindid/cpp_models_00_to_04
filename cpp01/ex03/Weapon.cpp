/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:43:16 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/02 13:00:53 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("default"){}

Weapon::Weapon (std::string weaponType) {
	
	type = weaponType;
}

void Weapon::setType(std::string newType) {
	type = newType;
}

const std::string& Weapon::getType() {
	const std::string& typeRef = type;
	return typeRef;
}