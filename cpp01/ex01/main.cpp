/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:34:08 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/01 18:54:42 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main () {
	
	Zombie* zombie;
	zombie = zombieHorde(100, "amine");
	for (int i = 0; i < 100; i++)
		zombie[i].announce();
}