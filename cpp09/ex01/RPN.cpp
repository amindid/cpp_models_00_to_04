/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:26:54 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/26 20:03:37 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void error_print(std::string message) {
	std::cerr << message << std::endl;
	exit(1);
}

bool invalid_input(char *input) {
	int i = 0;
	if (input && input[0] == '\0')
		return 1;
	while (input && input[i]) {
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '+' &&\
		input[i] != '*' && input[i] != '/' && input[i] != '-' && \
											!std::isdigit(input[i]))
			return 1;
		i++;
	}
	return 0;
}

void fill_containers(std::stack<int> & numbers, std::string input, std::stack<char> & operations) {
	int i = 0;
	int result;
	int num1;
	int num2;
	char operation;
	
	while(input[i]) {
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
				operations.push(input[i]);
		if (std::isdigit(input[i]) && input[i + 1] && std::isdigit(input[i + 1])) {
			if (input[i] != '0')
				error_print("Error : arguments containe number greater that 9.");
		}
		else if (std::isdigit(input[i]) && (!input[i + 1] || (input[i + 1] &&\
												!std::isdigit(input[i + 1]))))
			numbers.push(input[i] - '0');
		if (numbers.size() >= 2 && !operations.empty()) {
			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			operation = operations.top();
			operations.pop();
			result = calculate(num1, num2, operation);
			numbers.push(result);
		}
		i++;
	}
	if (operations.size() + 1 != numbers.size())
		error_print("Error : invalid RPN format.");
}

int calculate(int num1, int num2, char operation) {
	if (operation == '*')
		return num1 * num2;
	else if (operation == '/') {
		if (num2 == 0)
			error_print("devision by zero error.");
		return num1 / num2;
	}
	else if (operation == '+')
		return num1 + num2;
	else if (operation == '-')
		return num1 - num2;
	return 0;
}