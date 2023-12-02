/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:42:07 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/21 16:36:34 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : max_size(10000) {}

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span & copy) : max_size(copy.max_size) {
	for (int i = 0; i < (int)copy.elements.size(); i++)
		this->elements.push_back(copy.elements[i]);
}

Span &Span::operator=(const Span & copy) {
	if (this == &copy)
		return *this;
	this->elements.clear();
	this->max_size = copy.max_size;
	for (int i = 0; i < (int)copy.elements.size(); i++)
		this->elements.push_back(copy.elements[i]);
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (this->elements.size() == this->max_size)
		throw Span::maxReachedException();
	this->elements.push_back(number);
}

int Span::shortestSpan(void) {
	if (this->elements.size() == 1 || this->elements.empty())
		throw Span::NoSpanFoundException();
	int shortSpan;
	std::sort(this->elements.begin(), this->elements.end());
	shortSpan = this->elements[1] - this->elements[0];
	for (int i = 1; i < (int)this->elements.size() - 1; i++) {
		int tmp;
		tmp = this->elements[i + 1] - this->elements[i];
		if (tmp < shortSpan)
			shortSpan = tmp;
	}
	return shortSpan;
}

int Span::longestSpan(void) {
	if (this->elements.size() == 1 || this->elements.empty())
		throw Span::NoSpanFoundException();
	int longeSpan;
	std::sort(this->elements.begin(), this->elements.end());
	longeSpan = this->elements[this->elements.size() - 1] - this->elements[0];
	return longeSpan;
}

void Span::fillElements(unsigned int min, unsigned int max) {
	std::srand(time(NULL));
	for (unsigned int i = 0; i < max_size; i++) {
		int number = min + std::rand() % (max - min + 1);
		this->elements.push_back(number);
	}
}