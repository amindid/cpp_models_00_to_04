/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:20:04 by aouchaad          #+#    #+#             */
/*   Updated: 2023/11/26 15:23:11 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange() {
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange & copy) {
	(void)copy;
}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange & copy) {
	(void)copy;
	return *this;
}

void BitcoinExchange::readDataBase() {
	std::ifstream dataBase("data.csv");
	if (!dataBase)
		throw BitcoinExchange::CantOpenDataBaseFileException();
	std::string buffer;
	std::getline(dataBase, buffer);
	if (buffer != "date,exchange_rate") {
		std::cout << "invalid or missing header." << std::endl;
		exit(1);
	}
	int _do = 0;
	while (std::getline(dataBase, buffer)) {
		if (buffer.empty())
			continue;
		try {
			errorsCheck(buffer, ',');
			_DataBase.insert(std::make_pair(changeFormat(), _bitcoin));
		} catch (std::exception &e) {
			std::cout << "ERROR : " << e.what() << std::endl;
			_do = 1;
		}
	}
	if (_do)
		exit(1);
}

int BitcoinExchange::changeFormat(void) {
	int value = 0;
	value += _date[0] * 10000;
	value += _date[1] * 100;
	value += _date[2];

	return value;
}

void BitcoinExchange::errorsCheck(std::string &line, char separator) {
	BitcoinExchange::badInputChecks(line, separator);
	BitcoinExchange::eraseSpacesAndTabs(line);
	BitcoinExchange::checkDateErrors(line);
	BitcoinExchange::checkBitcoinValue(line, separator);
}

void BitcoinExchange::eraseSpacesAndTabs(std::string &line) {
	std::string::iterator it;

	it = line.begin();
	while (it != line.end()) {
		if (*it == ' ' || *it == '\t')
			it = line.erase(it);
		else
			it++;
	}
}

void BitcoinExchange::badInputChecks(std::string &line, char separator) {
	std::string::iterator it = line.begin();
	while (it != line.end() && (*it == '\t' || *it == ' '))
		it++;
	if (!std::isdigit(*it))
		throw badInputEception();
	int count = 0;
	int pointcount = 0;
	while (it != line.end()) {
		if (it != line.end() && std::isdigit(*it)) {
			count++;
			while (it != line.end() && std::isdigit(*it))
				it++;
		}
		if (it != line.end() && *it == '-') {
			count++;
			it++;
			if (it != line.end() && !std::isdigit(*it))
				throw badInputEception();
		}
		if (it != line.end() && *it == separator) {
			count++;
			it++;
			if ((it != line.end() && *it == separator) || count != 6)
				throw badInputEception();
		}
		if (it != line.end() && *it == '.') {
			pointcount++;
			if (pointcount > 1)
				throw badInputEception();
			it++;
			while (it != line.end() && std::isdigit(*it))
				it++;
		}
		while (it != line.end() && (*it == ' ' || *it == '\t'))
			it++;
		if (it != line.end() && !std::isdigit(*it) && *it != '-' &&\
							 *it != separator && *it != ' ' && *it != '\t')
			throw badInputEception();
	}
	if (count == 8) {
		it = line.end();
		it--;
		while (it != line.begin() && (*it == '\t' || *it == ' '))
			it--;
		while (it != line.begin() && std::isdigit(*it))
			it--;
		if (it != line.begin() && *it == '-')
			throw NotAPositiveNumberEception();
		throw badInputEception();
	}
	if (count != 7)
		throw badInputEception();
}

void BitcoinExchange::checkDateErrors(std::string &line) {
	int begin = 0;
	int end;
	int index = 0;
	for (int i = 0; i < (int)line.size(); i++) {
		if (index > 2)
			break;
		if (!std::isdigit(line[i])) {
			end = i;
			_date[index++] = std::atoi(line.substr(begin, end - begin).c_str());
			begin = end + 1;
		}
	}
	if (_date[0] < 2009 || _date[0] > 2023)
		throw InvalidDateFormatEception();
	if (_date[1] < 1 || _date[1] > 12)
		throw InvalidDateFormatEception();
	if (_date[2] < 1 || _date[2] > 31)
		throw InvalidDateFormatEception();
	specialDates(_date[0], _date[1], _date[2]);
}

void BitcoinExchange::checkBitcoinValue(std::string &line, char separator) {
	int i = 0;
	while (i < (int)line.size()) {
		if (line[i] == separator) {
			i++;
			break;
		}
		i++;
	}
	char *endptr;
	_bitcoin = strtod(line.substr(i, line.size() - i).c_str(), &endptr);
	if (_bitcoin > 1000 && separator == '|')
		throw TooLargeNumberEception();
}

void BitcoinExchange::calculate(char *fileName) {
	readDataBase();
	std::ifstream inputFile(fileName);
	if (!inputFile)
		throw BitcoinExchange::CantOpenInputFileException();
	std::string buffer;
	std::getline(inputFile, buffer);
	if (buffer != "date | value") {
		std::cout << "invalid or missing header." << std::endl;
		exit(1);
	}
	while (std::getline(inputFile, buffer)) {
		if (buffer.empty())
			continue;
		try {
			errorsCheck(buffer, '|');
			std::map<int, double>::iterator it;
			int date = changeFormat();
			it = _DataBase.lower_bound(date);
			if (it->first != date)
				it--;
			std::cout << extructDate(buffer) << " => " << _bitcoin << " = "<< \
											it->second * _bitcoin << std::endl;
		} catch (std::exception &e) {
			std::cout << "ERROR : " << e.what() << std::endl;
		}
	}
}

std::string BitcoinExchange::extructDate(std::string & line) {
	std::string date;
	std::string::iterator it = line.begin();
	while (it != line.end()) {
		if (*it == '|')
			break;
		date += *it;
		it++;
	}
	return date;
}

void BitcoinExchange::specialDates(int year, int mounth, int day) {
	if (mounth == 2 && (day > 29 || (day == 29 && year % 4 != 0)))
		throw InvalidDateFormatEception();
	if (day == 31) {
		if (mounth < 8 && mounth % 2 == 0)
			throw InvalidDateFormatEception();
		if (mounth > 8 && mounth % 2 != 0)
			throw InvalidDateFormatEception();
	}
	// first date in data base.
	if (year == 2009 && mounth == 1 && day < 2)
		throw InvalidDateFormatEception();
	// last date in data base.
	if (year == 2022 && mounth >= 3) {
		int _do = 1;
		if (mounth == 3 && day <= 29)
			_do = 0;
		if (_do)
			throw InvalidDateFormatEception();
	}
}