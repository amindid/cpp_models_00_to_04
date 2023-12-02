/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:25:08 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/29 19:47:07 by aouchaad         ###   ########.fr       */
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
	// vectorOfPairs numbers;
	vector rest;
	PmergeMe pmergeme;
	int count = 0;
	for (int i = 1; av[i]; i++) {
		for (int j = 0; av[i][j]; j++) {
			if (!std::isdigit(av[i][j]))
				error_print("ERROR");
		}
		pmergeme.firstInput.push_back(std::atoi(av[i]));
		count++;
	}
	std::cout << count << std::endl;
	// while (i <= count) {
	// 	vector tmp1;
	// 	vector tmp2;
	// 	tmp1.push_back(std::atoi(av[i]));
	// 	i++;
	// 	tmp2.push_back(std::atoi(av[i]));
	// 	i++;
	// 	if (*(tmp1.begin()) <= *(tmp2.begin()))
	// 		pmergeme.mainVect.push_back(std::make_pair(tmp1, tmp2));
	// 		// numbers.push_back(std::make_pair(tmp1, tmp2));
	// 	else
	// 		pmergeme.mainVect.push_back(std::make_pair(tmp2, tmp1));
	// 		// numbers.push_back(std::make_pair(tmp2, tmp1));
	// 	if (count % 2 != 0 && i == count) {
	// 		rest.push_back(std::atoi(av[i]));
	// 		break;
	// 	}
	// }
	vectOfPrs_it numbers_it = pmergeme.mainVect.begin();
	while (numbers_it != pmergeme.mainVect.end()) {
		std::cout << *((*numbers_it).first.begin())<< "\t" << *((*numbers_it).second.begin()) << std::endl;
		numbers_it++;
	}
	if (!rest.empty())
		std::cout << "----" << *(rest.begin()) << "----" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	pmergeme.Psort();
	numbers_it = pmergeme.mainVect.begin();
	while (numbers_it != pmergeme.mainVect.end()) {
		vect_it vit = (*numbers_it).first.begin();
		while (vit != (*numbers_it).first.end()){
			std::cout << *vit << "\t";
			vit++;
		}
		std::cout << "---\t";
		vit = (*numbers_it).second.begin();
		while (vit != (*numbers_it).second.end()){
			std::cout << *vit << "\t";
			vit++;
		}
		std::cout << std::endl;
		numbers_it++;
	}
	vect_it v_it = rest.begin();
	while (v_it != rest.end()) {
		std::cout << "-- " << *v_it << " --";
		v_it++;
	}
	std::cout << std::endl;
	return 0;
}