/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:17:36 by aouchaad          #+#    #+#             */
/*   Updated: 2023/09/30 13:49:28 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "main.hpp"
#include <iostream>
#include <iomanip>

void PhoneBook::countContacts() {
	if (PhoneBook::numContacts < 8)
		PhoneBook::numContacts++;
	PhoneBook::toBeReplaced++;
	if (PhoneBook::toBeReplaced >= 8)
		PhoneBook::toBeReplaced = 0;
}

void PhoneBook::initNumContacts() {
	PhoneBook::numContacts = 0;
	PhoneBook::toBeReplaced = 0;
}

void PhoneBook::addContact() {
	contact[toBeReplaced].replaceContact();
	countContacts();
}

void PhoneBook::searchContact() {
	std::string index;
	while (1)
	{
		std::cout << "enter wanted contact's index : ";
		if(!(std::cin >> index))
			exit(0);
		if (valid_index(index, numContacts))
		{
			contact[std::stoi(index) - 1].displayContact();
			break;
		}
		else
			std::cout << "invalid index" << std::endl;	
	}
}

void PhoneBook::searchDisplay() {
	
	contactData  data;
	
	for (int i = 0; i < numContacts; i++)
	{
		data = contact[i].getData();
		std::cout << i + 1 << std::setw(9);
		std::cout << "|";
		displayWord(data.firstName);
		displayWord(data.lastName);
		displayWord(data.nickName);
		std::cout << std::endl;
	}
}

void PhoneBook::displayAllContacts(void) {

	if (numContacts == 0)
	{
		std::cout << "the phone book is empty" << std::endl;
		return;
	}
	searchDisplay();
	PhoneBook::searchContact();
}

