/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:25:09 by aouchaad          #+#    #+#             */
/*   Updated: 2023/09/30 13:13:55 by aouchaad         ###   ########.fr       */
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
	std::cout << std::endl << "first name : ";
	std::cin >> newData.newFirstName;
	std::cout << "last name : ";
	std::cin >> newData.newLastName;
	std::cout << "nick name : ";
	std::cin >> newData.newNickName;
	std::cout << "phone number : ";
	std::cin >> newData.newPhoneNumber;
	std::cout << "darkest secret : ";
	std::cin >> newData.newDarckestSecret;
	Contact::setData(newData.newFirstName, newData.newLastName, newData.newNickName,
	newData.newPhoneNumber, newData.newDarckestSecret);
	std::cout << "contact added successfully ." << std::endl;
}

void Contact::displayContact(void) {
	contactData data;

	data = Contact::getData();
	std::cout << "first name : " << data.firstName << std::endl;
	std::cout << "last name : " << data.lastName << std::endl;
	std::cout << "nick name : " << data.nickName << std::endl;
	std::cout << "phone number : " << data.phoneNumber << std::endl;
	std::cout << "darkest secret : " << data.darkestSecret << std::endl;
}