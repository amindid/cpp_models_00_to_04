/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:25:50 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/01 15:07:31 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie* newZombie;

	newZombie = new Zombie;
	newZombie->setName(name);
	return newZombie;
}