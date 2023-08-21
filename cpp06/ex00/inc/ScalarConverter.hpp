/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:53:51 by verdant           #+#    #+#             */
/*   Updated: 2023/07/31 11:35:39 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <iomanip>

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	ERROR
} t_type;

class ScalarConverter
{
private:
	bool		_isChar;
	bool		_isInt;
	bool		_isFloat;
	bool		_isDouble;
	std::string _input;
public:
	ScalarConverter(void);
	ScalarConverter(std::string input);
	~ScalarConverter(void);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	int			identify( void );
	static void	convert( std::string input);
	void		isCharPrintable( char c );
	void		print(int i, float f, double d);
	void		printPseudo(std::string one, std::string two);
};