/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:05:44 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/22 12:42:07 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) {
	this->Stack = copy.Stack;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy) {
	while (!(this->Stack.empty()))
		this->Stack.pop();
	this->Stack = copy.Stack;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) {
	return this->c.begin();
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) {
	return this->c.;
}