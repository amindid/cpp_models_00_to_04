/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:11:48 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/16 15:32:11 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : arr(nullptr), lenth(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : lenth(n){
	this->arr = new T[lenth]();
}

template <typename T>
Array<T>::Array(const Array &copy) : lenth(copy.lenth) {
	this->arr = new T[lenth]();
	for (unsigned int i = 0; i < this->lenth; i++)
		this->arr[i] = copy.arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array & copy) {
	if (this == &copy)
		return *this;
	delete[] arr;
	this->lenth = copy.lenth;
	this->arr = new T[this->lenth]();
	for (unsigned int i = 0; i < this->lenth; i++)
		this->arr[i] = copy.arr[i];
	return *this;
}

template <typename T>
unsigned int Array<T>::size(void) const{
	return this->lenth;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->lenth)
		throw std::out_of_range("index out of bounds lol.");
	return this->arr[index];
}

template <typename T>
Array<T>::~Array() {
	delete[] arr;
}