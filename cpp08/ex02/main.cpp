/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:59:37 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/21 16:45:32 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>

void _main(void) {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

int main(void) {
	MutantStack<int> test;
	MutantStack<int>::iterator it;

	test.push(10);
	test.push(20);
	test.push(30);
	test.push(40);
	it = test.begin();
	*it = 30;
	std::cout << *test.begin() << std::endl;
	while (it != test.end()) {
		std::cout << *it << std::endl;
		it++;
	}
	_main();
	return 0;
}