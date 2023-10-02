/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:54:25 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/02 10:16:30 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main () {
	
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << &str << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}