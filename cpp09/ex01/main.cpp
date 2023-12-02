/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:27:23 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/26 20:02:58 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2 || invalid_input(av[1]))
		error_print("Error");
	std::stack<int> numbers;
	std::stack<char> operations;
	std::string input(av[1]);
	fill_containers(numbers, input, operations);
	std::cout << numbers.top() << std::endl;
	return 0;
}