/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:48:31 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/20 16:22:23 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat (const WrongCat &wrongcat) {
	this->type = "WrongCat";
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = wrongcat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat) {
	if (this != &wrongcat)
		this->type = wrongcat.type;
	return *this;
}

WrongCat::~WrongCat () {
	std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound(void) const{
	std::cout << "WrongCat sound meoowwww" << std::endl;
}