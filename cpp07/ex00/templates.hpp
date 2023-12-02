/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:25:34 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/12 12:41:15 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>

template <typename T> void swap(T &a, T &b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T> T min(T &a, T &b) {
	return (a < b ? a : b);
}

template <typename T> T max(T &a, T &b) {
	return (a > b ? a : b);
}

#endif