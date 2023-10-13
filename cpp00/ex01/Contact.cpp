/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:25:09 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/11 11:31:44 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "main.hpp"

void Contact::setData(std::string newFirstName, std::string newLastName,
std::string newNickName, std::string newPhoneNumber, std::string newDarkestSecret) {
	data.firstName = newFirstName;
	data.lastName = newLastName;
	data.nickName = newNickName;
	data.phoneNumber = newPhoneNumber;
	data.darkestSecret = newDarkestSecret;	
}

contactData Contact::getData (void) {
	return data;
}

void Contact::replaceContact(void) {
	newData newData;
	std::cout << "enter contact information";
	std::cout << std::endl << "* First name     : ";
	if(!(std::cin >> newData.newFirstName))
		exit(0);
	std::cout << "* Last name      : ";
	if(!(std::cin >> newData.newLastName))
		exit(0);
	std::cout << "* Nick name      : ";
	if(!(std::cin >> newData.newNickName))
		exit(0);
	std::cout << "* Phone number   : ";
	if(!(std::cin >> newData.newPhoneNumber))
		exit(0);
	std::cout << "* Darkest secret : ";
	if(!(std::cin >> newData.newDarckestSecret))
		exit(0);
	Contact::setData(newData.newFirstName, newData.newLastName, newData.newNickName,
	newData.newPhoneNumber, newData.newDarckestSecret);
	std::cout << "contact added successfully ." << std::endl;
}

void Contact::displayContact(void) {
	contactData data;

	data = Contact::getData();
	std::cout << "* First name     : " << data.firstName << std::endl;
	std::cout << "* Last name      : " << data.lastName << std::endl;
	std::cout << "* Nick name      : " << data.nickName << std::endl;
	std::cout << "* Phone number   : " << data.phoneNumber << std::endl;
	std::cout << "* Darkest secret : " << data.darkestSecret << std::endl;
}