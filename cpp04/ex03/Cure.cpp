/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:30:32 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/27 12:20:17 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	type = "cure";
	std::cout << "Cure default constructor called." << std::endl;
}
Cure::Cure(const Cure &copy) {
	type = copy.type;
	std::cout << "Cure copy constructor called." << std::endl;
}
Cure::~Cure() {
	std::cout << "Cure destructor called." << std::endl;
}
Cure &Cure::operator=(const Cure &copy) {
	if (this != &copy)
		this->type = copy.type;
	return *this;
}

AMateria* Cure::clone() const{
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}