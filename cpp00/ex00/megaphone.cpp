/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:49:52 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/02 15:53:37 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int i = 1; av[i]; i++) {
			for (int j = 0; av[i][j] != '\0'; j++)
				std::cout << (char)toupper(av[i][j]);
		}
	}
	std::cout << std::endl;
}
