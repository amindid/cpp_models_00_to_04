/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:35:13 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/02 12:57:59 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main () {
	{	
		// const Animal* meta = new Animal();
		Animal* j = new Dog();
		Dog *a = static_cast<Dog *>(j);
		// const Animal* i = new Cat();
	// 	std::cout << j->getType() << " " << std::endl;
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound();
		a->makeSound();
	// 	meta->makeSound();
	// 	delete meta;
	// 	delete i;
	// 	delete j;
	// }
	// std::cout << "---------------------------------------------" << std::endl;
	// {	
	// 	const WrongAnimal* meta = new WrongAnimal();
	// 	const WrongAnimal* i = new WrongCat();
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound();
	// 	meta->makeSound();
		// delete meta;
		// delete i;
	}
	return 0;
}