/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:53:51 by verdant           #+#    #+#             */
/*   Updated: 2023/07/20 15:54:43 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	PSEUDO_FLOAT,
	DOUBLE,
	PSEUDO_DOUBLE,
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
	void		isCharPrintable( int c );
};