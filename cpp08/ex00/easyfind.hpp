/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:36:38 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/21 16:30:50 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

class elementNotFoundException : public std::exception {
	public:
		const char *what() const throw() {
			return "element not found";
		}
};

template <typename T> void easyfind(T elements, int toFind) {
	typename T::iterator it = std::find(elements.begin(), elements.end(), toFind);
	if (it != elements.end())
		std::cout << toFind << " exist in the container." << std::endl;
	else
		throw elementNotFoundException();
}