/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:17:41 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/27 12:13:55 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "MateriaSource default constructor called." << std::endl;
}
MateriaSource::MateriaSource(const MateriaSource &copy) {
	for(int i = 0; i < 4; i++) {
		if (!copy.inventory[i])
			this->inventory[i] = NULL;
		else {
			this->inventory[i] = copy.inventory[i]->clone();
		}
	}
	std::cout << "MateriaSource copy constructor called." << std::endl;
}
MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i]) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	std::cout << "MateriaSource destructor called." << std::endl;
}
MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
	if (this == &copy)
		return *this;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i]) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	for(int i = 0; i < 4; i++) {
		if (!copy.inventory[i])
			this->inventory[i] = NULL;
		else {
			this->inventory[i] = copy.inventory[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return;
	for(int i = 0; i < 4; i++) {
		if (!this->inventory[i])
		{
			this->inventory[i] = m->clone();
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i]->getType() == type) {
			return this->inventory[i]; 
		}
	}
	return NULL;
}