/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:36:07 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/20 16:23:05 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constrictor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal) {
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = wronganimal;
}

WrongAnimal::~WrongAnimal (){
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal) {
	if (this != &wronganimal)
		this->type = wronganimal.type;
	return *this;
}

void WrongAnimal::makeSound(void) const{
	std::cout << "WrongAnimal sound AHHOOOOOO" << std::endl;
}

std::string WrongAnimal::getType(void) const{
	return this->type;
}

