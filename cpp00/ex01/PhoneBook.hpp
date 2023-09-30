/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:55:18 by aouchaad          #+#    #+#             */
/*   Updated: 2023/09/30 13:49:53 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook {
	private:
		Contact contact[8];
		int numContacts;
		int toBeReplaced;

	public:
		void addContact();
		void searchContact();
		void searchDisplay();
		void displayAllContacts();
		void initNumContacts();
		void countContacts(void);
};

#endif