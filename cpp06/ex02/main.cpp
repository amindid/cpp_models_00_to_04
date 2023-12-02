/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:48:03 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/11 12:14:42 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.hpp"
#include "Base.hpp"

int main(void) {
	
	Base* opject = generate();

	std::cout << "-----identify type using pointer-----" << std::endl;
	identify(opject);
	std::cout << "-----identify type using reference-----" << std::endl;
	identify(*opject);
	
	delete opject;
	return 0;
}