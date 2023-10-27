/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:59:37 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/27 12:19:23 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	std::cout << "Character default constructor called." << std::endl;
	this->trashHolder = new UnequipedAmateria();
	this->name = "character";
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name) {
	std::cout << "Character " << this->name <<  " parametrized constructor called." << std::endl;
	this->trashHolder = new UnequipedAmateria();
	this->name = name;
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character &copy) {
	this->name = copy.name;
	for(int i = 0; i < 4; i++) {
		if (!copy.inventory[i])
			this->inventory[i] = NULL;
		else {
			this->inventory[i] = copy.inventory[i]->clone();
		}
	}
	this->trashHolder = copy.trashHolder;
	std::cout << "Character " << this->name << " copy constructor called." << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i]) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	delete this->trashHolder;
	this->trashHolder = NULL;
	std::cout << "Character " << this->name << " destructor called." << std::endl;
}

Character &Character::operator=(const Character &copy) {
	if (this == &copy)
		return *this;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i]) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	this->trashHolder->emptyTrash();
	this->name = copy.name;
	for(int i = 0; i < 4; i++) {
		if (!copy.inventory[i])
			this->inventory[i] = NULL;
		else {
			this->inventory[i] = copy.inventory[i]->clone();
		}
	}
	this->trashHolder = copy.trashHolder;
	return *this;
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!this->inventory[i])
		{
			this->inventory[i] = m->clone();
			break;
		}
	}
}

void Character::unequip(int idx) {
	for(int i = 0; i < 4; i++) {
		if (i == idx && this->inventory[idx]) {
			this->trashHolder->moveToTrash(this->inventory[idx]);
			this->inventory[idx] = NULL;
			break;
		}	
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->inventory[idx]) {
		this->inventory[idx]->use(target);
	}
}

std::string const &Character::getName(void) const {
	return this->name;
}