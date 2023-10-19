/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:57:35 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/19 12:47:34 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->name = "ScavTrap";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	
	return *this;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0)
		std::cout << "ScavTrap " << this->name << " cannot attack no energy points left" << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "ScavTrap " << this->name << " cannot attack no hit points left" << std::endl;
	else {
		std::cout << "ScavTrap " << this->name << " attacks " << target << \
		", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}