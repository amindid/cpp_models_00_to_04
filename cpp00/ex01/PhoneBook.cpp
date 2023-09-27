/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:17:36 by aouchaad          #+#    #+#             */
/*   Updated: 2023/09/27 17:27:28 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact(int index) {
	std::cout << "first name : ";
	std::cin >> Contact[index]::firstName;
	std::cout << "last name :" << std::endl;
	std::cin >> Contact[index]::lastName;
	std::cout << "nick name :" << std::endl;
	std::cin >> Contact[index]::nickName;
	std::cout << "phone number :" << std::endl;
	std::cin >> Contact[index]::phoneNumber;
	std::cout << "darkest secret :" << std::endl;
	std::cin >> Contact[index]::darkestSecret;
}

void PhoneBook::searchContact(int index) {
	
}

