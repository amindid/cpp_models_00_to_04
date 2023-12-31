/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:48:31 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/27 16:33:36 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->type = "Cat";
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat (const Cat &cat) {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
	if (this != &cat)
		this->type = cat.type;
	return *this;
}

Cat::~Cat () {
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound(void) const{
	std::cout << "Cat sound meoowwww" << std::endl;
}