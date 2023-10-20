/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:07:59 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/20 08:55:14 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = "FragTrap";
	this->hitPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "FragTrap parameterized constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	
	return *this;
}

void FragTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0)
		std::cout << "FragTrap " << this->name << " cannot attack no energy points left" << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "FragTrap " << this->name << " cannot attack no hit points left" << std::endl;
	else {
		std::cout << "FragTrap " << this->name << " attacks " << target << \
		", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap : High Fives Guys !!!" << std::endl;
}