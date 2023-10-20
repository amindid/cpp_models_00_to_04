/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:52:19 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/20 11:13:17 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->name = "DiamondTrap";
	ClapTrap::name = "DiamondTrap_clap_name";
	this->hitPoints = 0;
	this->energyPoints = 0;
	this->attackDamage = 0;
}

DiamondTrap::DiamondTrap(std::string name) {
	std::cout << "DiamondTrap parameterized constructor called" << std::endl;
	this->name = name;
	ClapTrap::name = name + "_clup_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy) {
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	
	return *this;
}

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	std::cout << "my name : " << this->name << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::name << std::endl;
}

std::string DiamondTrap::getDiamondName(void) {
	return this->name;
}