/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:20:18 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/10 12:00:20 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>

int main(void) {
	std::string input;
	
	while (true) {
		std::cout << "inter value : ";
		if (!(std::getline(std::cin ,input)))
			break;
		if (input.empty())
			continue;
		ScalarConverter::convert(input);
	}
	return 0;
}