/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:03:32 by verdant           #+#    #+#             */
/*   Updated: 2023/10/11 13:37:54 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;



#define KEY_LENGTH	10
#define CHECK_PIPE	11
#define MONTH		0
#define DAY			1

class BitcoinExchange {
private:
	std::map<std::string, float>	_map;
	string							_date;
	float							_value;
	float							_csvValue;

public:
	/* Orthodox Canonical Form */

	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange& operator=(const BitcoinExchange& src);

	/* Utility Functions */

	static bool				checkValidRange(const string& date, int type);
	template <typename T> T	printErr(string must, string opt, T retVal);

	/* Member Functions */

	void					parseCSV( string filename );
	void					calcValue(string filename );
	void					lookupExchangeRate( void );
	bool					checkInputFile(string& line);

};

