/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:56:13 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 12:42:12 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _input("0") {
	_isChar = false;
	_isInt = false;
	_isFloat = false;
	_isDouble = false;
}

ScalarConverter::ScalarConverter(std::string input) : _input(input) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other)
		this->_input = other._input;
	return (*this);
}


void	ScalarConverter::isCharPrintable( char c )
{
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;	
}

int	ScalarConverter::identify( void )
{
	std::string::iterator it = _input.begin();

	if (_input.length() == 1 && !isdigit(_input[0]))
		return (CHAR);
	if (_input.find("nanf") != std::string::npos || _input.find("inff") != std::string::npos)
		return (PSEUDO);
	if (_input.find("inf") != std::string::npos || _input.find("nan") != std::string::npos)
		return (PSEUDO);
	if (_input.find(".") != std::string::npos && _input.find("f") != std::string::npos)
	{
		int pos = _input.find("f");
		if (!isdigit(_input[pos - 1]))
			return (ERROR);
		return (FLOAT);
	}
	if (_input.find(".") != std::string::npos)
		return (DOUBLE);
	while (it != _input.end())
	{
		if (isdigit(*it) || *it == '-')
			it++;
		else
			return (ERROR);
	}
	return (INT);
}

void	ScalarConverter::print(int i, float f, double d)
{
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::printPseudo(std::string one, std::string two)
{
	std::cout << "float: " << one << std::endl;
	std::cout << "double: " << two << std::endl;
}

void ScalarConverter::convert(std::string input)
{
	ScalarConverter sc(input);
		
	switch (sc.identify()) {
		case CHAR:
			try {		
				sc.isCharPrintable(static_cast<char>(input[0]));
				sc.print(static_cast<int>(input[0]), static_cast<float>(input[0]), static_cast<double>(input[0]));
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			break;
		case INT:
			try {
				int i = std::stoi(input);
				sc.isCharPrintable(static_cast<char>(i));
				sc.print(i, static_cast<float>(i), static_cast<double>(i));
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			break;
		case FLOAT:
			try {
				float f = std::stof(input);
				sc.isCharPrintable(static_cast<char>(f));
				sc.print(static_cast<int>(f), f, static_cast<double>(f));
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			break;
		case DOUBLE:
			try {
				double d = std::stod(input);
				sc.isCharPrintable(static_cast<char>(d));
				sc.print(static_cast<int>(d), static_cast<float>(d), d);
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			break;
		case PSEUDO:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (input.find("nan") != std::string::npos)
				sc.printPseudo("nanf", "nan");
			else if (input.find("-") != std::string::npos)
				sc.printPseudo("-inff", "-inf");
			else
				sc.printPseudo("inff", "inf");
			break;
		default:
			 std::cout << "Error: Invalid input" << std::endl;
		}
}
