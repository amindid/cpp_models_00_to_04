/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:48:31 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/27 16:58:03 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Cat default constructor called." << std::endl;
	this->type = "Cat";
	this->CatBrain = new Brain();
}

Cat::Cat (const Cat &cat) {
	std::cout << "Cat copy constructor called." << std::endl;
	this->CatBrain = new Brain();
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
	if (this != &cat)
	{
		this->type = cat.type;
		*this->CatBrain = *cat.CatBrain;
	}
	return *this;
}

Cat::~Cat () {
	std::cout << "Cat destructor called." << std::endl;
	delete this->CatBrain;
}

void Cat::makeSound(void) const{
	std::cout << "Cat sound meoowwww" << std::endl;
}