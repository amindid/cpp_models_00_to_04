/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:25:09 by aouchaad          #+#    #+#             */
/*   Updated: 2023/09/27 17:19:01 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::replaceContact(void) {
	std::cout << std::endl << "first name : ";
	std::cin >> Contact::firstName;
	std::cout << std::endl << "last name : ";
	std::cin >> Contact::lastName;
	std::cout << std::endl << "nick name :" << std::endl;
	std::cin >> Contact::nickName;
	std::cout << std::endl << "phone number : ";
	std::cin >> Contact::phoneNumber;
	std::cout << std::endl << "darkest secret : ";
	std::cin >> Contact::darkestSecret;
}

void Contact::displayContact(void) {
	
	std::cout << "first name : " << Contact::firstName << std::endl;
	std::cout << "last name : " << Contact::lastName << std::endl;
	std::cout << "nick name : " << Contact::nickName << std::endl;
	std::cout << "phone number : " << Contact::phoneNumber << std::endl;
	std::cout << "darkest secret : " << Contact::darkestSecret << std::endl;
}