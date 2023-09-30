/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:53:31 by aouchaad          #+#    #+#             */
/*   Updated: 2023/09/30 13:50:31 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

typedef struct newData {
	std::string newFirstName;
	std::string newLastName;
	std::string newNickName;
	std::string newPhoneNumber;
	std::string newDarckestSecret;
} newData;

int valid_index(std::string index, int numContacts);
void displayWord(std::string word);

#endif