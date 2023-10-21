/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:35:13 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/21 08:41:51 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

void _main(void) {
	int size = 3;
	Animal* animals[size];
	for(int i = 0; i < size; i++) {
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	
	for(int i = 0; i < size; i++)
		animals[i]->makeSound();
	
	for(int i = 0; i < size; i++)
		delete animals[i];
}

int main () {
	_main();
	// system ("leaks Animals");
	return 0;
}