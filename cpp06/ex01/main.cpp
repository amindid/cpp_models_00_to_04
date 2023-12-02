/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:13:01 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/11 11:09:29 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "data.hpp"

int main(void) {
	Data data;

	data.name = "amine";
	
	uintptr_t ptr = Serializer::serializer(&data);
	Data *deserializedData = Serializer::deserialize(ptr);

	if (deserializedData == &data) {
		std::cout << deserializedData->name << std::endl;
		std::cout << "successful." << std::endl;
	}
	else
		std::cout << "failed." << std::endl;
	return 0;
}