/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:31:22 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/26 16:47:37 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("default"){
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(const AMateria &copy) : type(copy.type) {
	std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type){
	std::cout << "AMateria parametrized constructor called." << std::endl;
}

AMateria::~AMateria () {
	std::cout << "AMateria destructor called." << std::endl;
}

AMateria &AMateria::operator=(const AMateria &copy) {
	(void)copy;
	return *this;
}

std::string const &AMateria::getType(void) const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}
