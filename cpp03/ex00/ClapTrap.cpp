/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:34:45 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/19 09:00:52 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "default constructor called" << std::endl;
	this->name = "ClapTrap";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "parameterized constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap() {
	std::cout << "destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0)
		std::cout << "ClapTrap " << this->name << " cannot attack no energy points left" << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " cannot attack no hit points left" << std::endl;
	else {
		std::cout << "ClapTrap " << this->name << " attacks " << target << \
		", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->name << " has been attacked, he lost " << \
	amount << " of hit points!" << std::endl;
	this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints <= 0)
		std::cout << "ClapTrap " << this->name << " cannot repaire no energy points left" << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " cannot repaire no hit points left" << std::endl;
	else {
		std::cout << "ClapTrap " << this->name << " repaired himself, he gained " \
		<< amount << " of hit points!" << std::endl;
		this->hitPoints += amount;
		this->energyPoints--;
	}
}

unsigned int ClapTrap::getHitPoints(void) const {
	return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const {
	return this->energyPoints;
}

std::string ClapTrap::getName(void) const {
	return this->name;
}