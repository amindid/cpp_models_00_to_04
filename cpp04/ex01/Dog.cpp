/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:18:44 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/20 19:47:23 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() :Animal(){
	this->dogBrain = new Brain();
	this->type = "Dog";
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog (const Dog &dog) {
	this->dogBrain = new Brain();
	this->type = "Dog";
	std::cout << "Dog copy constructor called." << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
	if (this != &dog)
		this->type = dog.type;
	return *this;
}

Dog::~Dog () {
	std::cout << "Dog destructor called." << std::endl;
	delete this->dogBrain;
}

void Dog::makeSound(void) const{
	std::cout << "Dog sound how how" << std::endl;
}