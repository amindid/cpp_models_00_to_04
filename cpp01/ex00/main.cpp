/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:31:10 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/01 15:23:27 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main () 
{
	Zombie* theNewZombie;

	theNewZombie = newZombie("amine1");
	theNewZombie->announce();
	randomChump("amine2");
	delete theNewZombie;
}