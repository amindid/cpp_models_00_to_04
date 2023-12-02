/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:49:55 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/13 17:44:10 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printnumber(int d) {
	std::cout << d << std::endl;
}

void printcaracter(char d) {
	std::cout << d << std::endl;
}

void printstring(std::string d) {
	std::cout << d << std::endl;
}

template <typename T> void printAllTypes (T element) {
	std::cout << element << std::endl;
}

int main (void) {
	
	int arr1[] = {1, 2, 3, 4};
	char arr2[] = {'a', 'b', 'c', 'd'};
	std::string arr3[] = {"one", "two", "three", "four"};
	std::cout << "------print numbers--------" << std::endl;
	iter <int> (arr1, 4, printnumber);
	iter <int> (arr1, 4, printAllTypes);
	std::cout << "------print caracters--------" << std::endl;
	iter <char> (arr2, 4, printcaracter);
	iter <char> (arr2, 4, printAllTypes);
	std::cout << "------print strings--------" << std::endl;
	iter <std::string> (arr3, 4, printstring);
	iter <std::string> (arr3, 4, printAllTypes);
}