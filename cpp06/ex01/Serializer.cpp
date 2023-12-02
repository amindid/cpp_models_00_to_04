/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:15:15 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/11 11:08:08 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &copy) {
	(void)copy;
}
Serializer::~Serializer() {}
Serializer &Serializer::operator=(const Serializer &copy) {
	(void)copy;
	return *this;
}

uintptr_t Serializer::serializer(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}