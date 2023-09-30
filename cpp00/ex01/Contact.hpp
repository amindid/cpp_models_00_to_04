/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:37:52 by aouchaad          #+#    #+#             */
/*   Updated: 2023/09/30 13:49:03 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

typedef struct contactData {
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
} contactData;

class Contact {
	private:
		contactData data;
	public:
		void setData (std::string newFirstName, std::string newLastName,
		std::string newNickName, std::string newPhoneNumber, std::string newDarkestSecret);
		contactData getData (void);
		void replaceContact(void);
		void displayContact(void);
};

#endif