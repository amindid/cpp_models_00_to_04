/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:26:14 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/21 16:36:51 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	private:
		unsigned int max_size;
		std::vector<int> elements;
	public:
		Span();
		Span(const Span & copy);
		Span(unsigned int N);
		~Span();
		Span &operator=(const Span & copy);
		
		class maxReachedException : public std::exception {
			public:
				const char *what() const throw() {
					return "no more elements can be added .";
				}
		};

		class NoSpanFoundException : public std::exception {
			public:
				const char *what() const throw() {
					return "no span can be found";
				}
		};
		
		void addNumber(int number);
		int shortestSpan(void);
		int longestSpan(void);
		void fillElements(unsigned int min, unsigned int max);
};