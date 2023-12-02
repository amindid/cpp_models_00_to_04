/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:53:45 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/21 16:30:37 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main (void) {
	
	std::vector<int> elements;
	int size = 100;
	int multip = 5;
	for (int i = 0; i < size; i++)
		elements.push_back(i * multip);
	try {
		easyfind(elements, 5);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}