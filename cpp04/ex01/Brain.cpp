/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:26:35 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/20 19:38:55 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain &brain) {
	std::cout << "Brain copy constructor called." << std::endl;
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain) {
	if (this != &brain) {
		for(int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}