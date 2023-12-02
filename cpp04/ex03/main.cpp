/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:59:03 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/10 18:25:10 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void _main(void) {
	IMateriaSource* src = new MateriaSource();
	Ice *ice1 = new Ice();
	Cure *cure1 = new Cure();
	src->learnMateria(ice1);
	src->learnMateria(cure1);
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout << "-----------------------------------------" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "-----------------------------------------" << std::endl;
	delete ice1;
	delete cure1;
	delete bob;
	delete me;
	delete src;
}

int main() {
	_main();
	std::cout << "_________________________________________" << std::endl;
	// system("leaks ex03");
	return 0;
}