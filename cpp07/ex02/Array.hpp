/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:49:09 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/15 22:49:23 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array {
	private:
		T *arr;
		unsigned int lenth;
	public :
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		Array &operator=(const Array &copy);
		~Array();

		unsigned int size(void) const;
		T &operator[](unsigned int index);
		
};

#include "Array.tpp"