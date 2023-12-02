/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:47:59 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/11 10:50:29 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>
#include "data.hpp"

class Serializer {
	private:
		Serializer();
	public:
		Serializer(const Serializer &copy);
		~Serializer();
		Serializer &operator=(const Serializer &copy);
		
		static uintptr_t serializer(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		
};

#endif