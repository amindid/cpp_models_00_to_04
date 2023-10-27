/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:36:07 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/27 16:56:02 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal &animal) {
	std::cout << "Animal copy constructor called." << std::endl;
	*this = animal;
}

Animal::~Animal (){
	std::cout << "Animal destructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
	if (this != &animal)
		this->type = animal.type;
	return *this;
}

std::string Animal::getType(void) const{
	return this->type;
}

