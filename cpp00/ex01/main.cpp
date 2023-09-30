/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:54:55 by aouchaad          #+#    #+#             */
/*   Updated: 2023/09/30 13:50:15 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

void displayWord(std::string word)
{
	if (word.length() > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << word[i];
		std::cout << '.';
	}
	else
		std::cout << word << std::setw(11 - word.length());
	std::cout << '|';
}

int valid_index(std::string index, int numContacts)
{
	for(unsigned long i = 0; i < index.length() ; i++)
	{
		if (index[i] < '0' || index[i] > '8')
			return (0);
	}
	if (std::stoi(index) <= 0 || std::stoi(index) > numContacts)
		return (0);
	return (1);
}

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	phoneBook.initNumContacts();
	while (1)
	{
		std::cout << "enter command : ";
		if(!(std::cin >> command))
			exit(0);
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.displayAllContacts();
		else if (command == "EXIT")
		{
			std::cout << "exit program" << std::endl;
			break;
		}
		else
		std::cout << "invalid input" << std::endl;
	}
	
	return (0);
}