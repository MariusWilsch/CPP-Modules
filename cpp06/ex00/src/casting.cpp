/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:56:13 by verdant           #+#    #+#             */
/*   Updated: 2023/07/20 15:57:09 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/casting.hpp"

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


void	ScalarConverter::isCharPrintable( int c )
{
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;	
}

int	ScalarConverter::identify( void )
{
	std::string::iterator it = _input.begin();
	bool	hasChar = false;
	bool	hasNum = false;

	while (it != _input.end())
	{
		if (isdigit(*it))
			hasNum = true;
		if (isalpha(*it))
			hasChar = true;
		if (hasChar && hasNum)
			return (ERROR);
		it++;
	}
	if (_input.length() == 1 && !isdigit(_input[0]))
		return (CHAR);
	if (_input.find("nanf") != std::string::npos || _input.find("inff") != std::string::npos)
		return (PSEUDO_FLOAT);
	if (_input.find("inf") != std::string::npos || _input.find("nan") != std::string::npos)
		return (PSEUDO_DOUBLE);
	if (_input.find(".f") != std::string::npos)
		return (FLOAT);
	if (_input.find(".") != std::string::npos)
		return (DOUBLE);
	return (INT);



	// if (_input.find("nan") != std::string::npos || _input.find("nanf") != std::string::npos)
	
}


void ScalarConverter::convert(std::string input)
{
	ScalarConverter sc(input);
	

	
	switch (sc.identify()) {
		case CHAR:
			try {		
				if (!isprint(input[0]))
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: '" << input[0] << "'" << std::endl;
				std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
				std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
				std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			break;
		case INT:
			try {
				int i = std::stoi(input);
				sc.isCharPrintable(static_cast<char>(i));
				std::cout << "int: " << i << std::endl;
				std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
				std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			break;
		case FLOAT:
			try {
				float f = std::stof(input);
				sc.isCharPrintable(static_cast<char>(f));
				std::cout << "int: " << static_cast<int>(f) << std::endl;
				std::cout << "float: " << f << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(f) << std::endl;
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			break;
		case DOUBLE:
			try {
				double d = std::stod(input);
				sc.isCharPrintable(static_cast<char>(d));
				std::cout << "int: " << static_cast<int>(d) << std::endl;
				std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
				std::cout << "double: " << d << std::endl;
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			break;
		case PSEUDO_FLOAT:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (input.find("nanf") != std::string::npos)
			{
				std::cout << "float: nanf" << std::endl;
				std::cout << "double: nan" << std::endl;
			}
			else if (input.find("inff") != std::string::npos)
			{
				std::cout << "float: inff" << std::endl;
				std::cout << "double: inf" << std::endl;
			}
			else
			{
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
			}
			break;
		case PSEUDO_DOUBLE:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (input.find("nan") != std::string::npos)
			{
				std::cout << "float: nanf" << std::endl;
				std::cout << "double: nan" << std::endl;
			}
			else if (input.find("inff") != std::string::npos)
			{
				std::cout << "float: inff" << std::endl;
				std::cout << "double: inf" << std::endl;
			}
			else
			{
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
			}
			break;
		default:
			 std::cout << "Error: Invalid input" << std::endl;
		}
}