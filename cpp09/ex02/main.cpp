/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:25:08 by aouchaad          #+#    #+#             */
/*   Updated: 2023/12/11 19:48:11 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void error_print(std::string message) {
	std::cerr << message << std::endl;
	exit(1);
}

int main(int ac, char **av) {
	if (ac < 3)
		error_print("ERROR");
	vector rest;
	PmergeMe pmergeme;
	int count = 0;
	for (int i = 1; av[i]; i++) {
		for (int j = 0; av[i][j]; j++) {
			if (!std::isdigit(av[i][j]))
				error_print("ERROR");
		}
		pmergeme.firstInput.push_back(std::atoi(av[i]));
		pmergeme.firstInputList.push_back(std::atoi(av[i]));
		count++;
	}
	pmergeme.Psort();
	return 0;
}