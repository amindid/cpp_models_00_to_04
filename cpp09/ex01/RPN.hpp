/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:27:09 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/26 19:52:11 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

bool invalid_input(char *input);
void error_print(std::string);
void fill_containers(std::stack<int> &numbers, std::string input,\
										std::stack<char> & operations);
int calculate(int num1, int num2, char operation);
