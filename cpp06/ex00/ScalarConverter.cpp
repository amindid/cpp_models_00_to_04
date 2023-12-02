/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:40:37 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/10 17:52:36 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter & copy) {
	(void)copy;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	(void)copy;
	return *this;
}
ScalarConverter::~ScalarConverter() {}


int calculatPrecision(std::string literal) {
	int count = 0;
	for (int i = 0; i < (int)literal.length(); i++) {
		if (literal[i] == 'f')
			break;
		if (count > 0)
			count++;
		if (literal[i] == '.')
			count++;
	}
	if (count - 1 < 0)
		return 1;
	return count - 1;
}

void printChar(double value) {
	if (value < 0 || value > 127)
		std::cout << "char   : impossible" << std::endl;
	else if (!std::isprint(value))
		std::cout << "char   : Non displayable" << std::endl;
	else
		std::cout << "char   : '" << static_cast <char> (value) << "'" << std::endl;
}

void printInt(double value) {
	if (value < INT_MIN || value > INT_MAX)
		std::cout << "int    : impossible" << std::endl;
	else
		std::cout << "int    : " << static_cast <int> (value) << std::endl;
}

void allImpossible(void) {
	std::cout << "char   : impossible" << std::endl;
	std::cout << "int    : impossible" << std::endl;
	std::cout << "float  : impossible" << std::endl;
	std::cout << "double : impossible" << std::endl;
}
void intToOthers(char literal) {
	double value = literal - '0';
	printChar(value);
	std::cout << "int    : " << static_cast <int> (value) << std::endl;
	std::cout << "float  : " << std::setprecision(1) << static_cast <float> (value) << "f" << std::endl;
	std::cout << "double : " << std::setprecision(1) <<  value << std::endl;
	
}
void charToOthers(char literal) {
	double value = static_cast <double> (literal);
	printChar(value);
	std::cout << "int    : " << static_cast <int> (literal) << std::endl;
	std::cout << "float  : " << std::setprecision(1) << static_cast <float> (literal) << "f" << std::endl;
	std::cout << "double : " << std::setprecision(1) << value  << std::endl;
}
void floatToOthers(std::string literal) {
	double value;
	value = std::stod(literal);
	printChar(value);
	printInt(value);
	std::cout << "float  : " << std::setprecision(calculatPrecision(literal)) << \
									static_cast <float> (value) << "f" << std::endl;
	std::cout << "double : " << std::setprecision(calculatPrecision(literal)) << \
										static_cast <double> (value) << std::endl;
		
}
void doubleToOthers(double doubleValue, std::string literal) {
	printChar(doubleValue);
	printInt(doubleValue);
	std::cout << "float  : " << std::setprecision(calculatPrecision(literal)) << \
							static_cast <float> (doubleValue) << "f" << std::endl;
	std::cout << "double : " << std::setprecision(calculatPrecision(literal)) << \
								static_cast <double> (doubleValue) << std::endl;
}

bool isPsudo(std::string literal) {
	std::string choices[6] = {"-inff", "+inff", "-inf", "+inf", "nan", "nanf"};
	int i = 0;
	while (i < 6) {
		if (choices[i] == literal)
			break;
		i++;
	}
	if (i == 6)
		return false;
	std::cout << "char   : impossible" << std::endl;
	std::cout << "int    : impossible" << std::endl;
	if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
		std::cout << "float  : " << literal << std::endl;
		std::cout << "double : " << literal.erase(literal.length() - 1, 1) << std::endl;
	}
	else if (literal == "-inf" || literal == "+inf" || literal == "nan") {
		std::cout << "float  : " << literal << "f" << std::endl;
		std::cout << "double : " << literal << std::endl;
	}
	return true;
}

void ScalarConverter::convert(std::string literal) {
	double doubleValue;
	char *theRest;
	
	doubleValue = std::strtod(literal.c_str(), &theRest);
	std::cout << std::fixed;
	if (literal.length() == 1) {
		if (!theRest[0])
			intToOthers(literal[0]);
		else
			charToOthers(literal[0]);
	}
	else if (isPsudo(literal))
		return;
	else {
		if (theRest[0]) {
			if (theRest[0] == 'f' && std::strlen(theRest) == 1)
				floatToOthers(literal);
			else
				allImpossible();
		}
		else
			doubleToOthers(doubleValue, literal);
	}
}