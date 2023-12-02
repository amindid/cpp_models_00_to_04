/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:45:38 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/26 12:21:35 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <fstream>
#include <cstdlib>

class BitcoinExchange {
	private:
		std::map<int, double> _DataBase;
		int _date[3];
		double _bitcoin;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & copy);
		BitcoinExchange &operator=(const BitcoinExchange & copy);
		virtual ~BitcoinExchange();
		class CantOpenDataBaseFileException : public std::exception {
			public:
				const char *what() const throw() {
					return "cant open data base file.";
				}
		};
		class CantOpenInputFileException : public std::exception {
			public:
				const char *what() const throw() {
					return "cant open input file.";
				}
		};
		class InvalidDateFormatEception : public std::exception {
			public:
				const char *what() const throw() {
					return "invalid date.";
				}
		};
		class NotAPositiveNumberEception : public std::exception {
			public:
				const char *what() const throw() {
					return "not a positive number.";
				}
		};
		class TooLargeNumberEception : public std::exception {
			public:
				const char *what() const throw() {
					return "too large number.";
				}
		};
		class badInputEception : public std::exception {
			public:
				const char *what() const throw() {
					return "bad input.";
				}
		};

		void readDataBase();
		int changeFormat(void);
		void errorsCheck(std::string &line, char separator);
		void checkDateErrors(std::string &line);
		void eraseSpacesAndTabs(std::string &line);
		void badInputChecks(std::string &line, char separator);
		void checkBitcoinValue(std::string & line, char separator);
		void calculate(char *fileName);
		std::string extructDate(std::string & line);
		void specialDates(int year, int mounth, int day);
};