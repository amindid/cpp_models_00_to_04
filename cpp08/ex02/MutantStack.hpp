/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:53:46 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/21 17:50:29 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <deque>

template <typename T> class MutantStack : public std::stack<T> {
	public:
		typedef typename  std::deque<T>::iterator iterator;
		MutantStack();
		MutantStack(const MutantStack & copy);
		~MutantStack();
		MutantStack &operator=(const MutantStack & copy);

		iterator begin(void); 
		iterator end(void);
};

#include "MutantStack.tpp"