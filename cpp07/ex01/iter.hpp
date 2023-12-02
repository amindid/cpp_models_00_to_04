/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:49:48 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/13 17:34:50 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T *arr, int arrLen, void (*f)(T element)) {
	for (int i = 0; i < arrLen; i++) {
		f(arr[i]);
	}
}

#endif