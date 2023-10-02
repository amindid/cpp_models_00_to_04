/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:35:40 by aouchaad          #+#    #+#             */
/*   Updated: 2023/10/02 20:40:16 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av) {
	
	if (ac != 4)
	{
		std::cout << "invalid arguments" << std::endl;
		exit(1);
	}
	std::string toBeReplaced = std::string(av[2]);
	if (toBeReplaced[0] == '\0')
	{
		std::cout << "invalid arguments" << std::endl;
		exit(1);
	}
	std::string fileName = std::string(av[1]);
	std::string replaceFile = fileName + ".replace";
	std::string bufferLine;
	std::string line;
	std::string replaceWith = std::string(av[3]);
	
	std::ifstream inputFile(fileName);
	if (!inputFile)
	{
		std::cout << "file dose not exists or cant be read" << std::endl;
		exit(1);
	}
	std::ofstream outputFile(replaceFile);
	if (!outputFile)
	{
		std::cout << replaceFile << "cant be openned" << std::endl;
		exit(1);
	}
	size_t firstPos;
	size_t nextPos;
	while (std::getline(inputFile, bufferLine))
	{
		firstPos = 0;
		nextPos = bufferLine.find(toBeReplaced);
		if (nextPos != std::string::npos)
		{
			while (nextPos != std::string::npos)
			{
				line = bufferLine.substr(0, nextPos) + replaceWith + bufferLine.substr(nextPos + \
				toBeReplaced.length(), bufferLine.length() - (nextPos + toBeReplaced.length()));
				firstPos = nextPos + toBeReplaced.length();
				bufferLine = line;
				nextPos = bufferLine.find(toBeReplaced, firstPos);
			}
			outputFile << line << std::endl;
		}
		else
		{
			if (inputFile.eof())
				outputFile << bufferLine;
			else
				outputFile << bufferLine << std::endl;
		}
	}
	inputFile.close();
	outputFile.close();
}