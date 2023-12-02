/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:52:57 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/16 16:07:40 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void _main(void) {
	unsigned int size = 5;
	Array<int> arr1(size);
	Array<int> arr2(size);
	for (unsigned int i = 0; i < size; i++)
		arr2[i] = i * 2;
	Array<int> arr3(arr2);
 	std::cout << arr1.size() << std::endl;
	std::cout << arr1[0] << std::endl;
	try {
		std::cout << arr1[size] << std::endl;
	} catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	arr1 = arr2;
	for (unsigned int i = 0; i < size; i++)
		std::cout << "arr1 " << arr1[i] << std::endl;
	for (unsigned int i = 0; i < size; i++)
		std::cout << "arr3 " << arr3[i] << std::endl;
}

void _main2(void) {
	unsigned int size = 5;
	Array<std::string> arr1(size);
	Array<std::string> arr2(size);
	for (unsigned int i = 0; i < size; i++) {
		arr2[i] = "hello";
	}
	Array<std::string> arr3(arr2);
 	std::cout << arr1.size() << std::endl;
	std::cout<< "[" << arr1[0] << "]" << std::endl;
	try {
		std::cout << arr1[size] << std::endl;
	} catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	arr1 = arr2;
	for (unsigned int i = 0; i < size; i++)
		std::cout << "arr1 " << arr1[i] << std::endl;
	for (unsigned int i = 0; i < size; i++)
		std::cout << "arr3 " << arr3[i] << std::endl;
}

int main (void) {
	_main();
	_main2();
	// system("leaks Array");
	return 0;
}