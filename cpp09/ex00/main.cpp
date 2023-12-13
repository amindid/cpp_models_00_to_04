/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:48:44 by aouchaad          #+#    #+#             */
/*   Updated: 2023/12/12 12:24:18 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "ERROR: missing file name in arguments." << std::endl;
		exit (1);
	}
	BitcoinExchange bitcoin;
	try {
		bitcoin.calculate(av[1]);
	} catch (std::exception &e) {
		std::cout << "ERROR : " << e.what() << std::endl;
	}
	return 0;
}