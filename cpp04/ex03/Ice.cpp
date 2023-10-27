/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:27:08 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/26 16:49:53 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {
	type = "ice";
	std::cout << "Ice default constructor called." << std::endl;
}
Ice::Ice(const Ice &copy) {
	type = copy.type;
	std::cout << "Ice copy constructor called." << std::endl;
}
Ice::~Ice() {
	std::cout << "Ice destructor called." << std::endl;
}
Ice &Ice::operator=(const Ice &copy) {
	if (this != &copy)
		this->type = copy.type;
	return *this;
}

AMateria* Ice::clone() const{
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}