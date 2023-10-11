/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:03:59 by verdant           #+#    #+#             */
/*   Updated: 2023/10/11 13:19:45 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void printMap(const std::map<std::string, float>& myMap) {
		if (myMap.empty()) {
				std::cout << "The map is empty." << std::endl;
				return;
		}

	std::map<string, float>::const_iterator it;
	for (it = myMap.begin(); it != myMap.end(); it++)
		cout << "Key : " << it->first << "\t Value: " << std::fixed << std::setprecision(2) << it->second << endl; 
}


/*			Orthodox Canonical Form			*/

BitcoinExchange::BitcoinExchange( void ) {}

BitcoinExchange::~BitcoinExchange ( void ) {}

BitcoinExchange::BitcoinExchange ( const BitcoinExchange& src ) : _map(src._map), _date(src._date), _value(src._value) {}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& src) {
	if (this == &src)
		return (*this);
	_map = src._map;
	_date = src._date;
	_value = src._value;
	return *this;
}

/*			Member Functions			*/


template <typename T> T BitcoinExchange::printErr(string must, string opt, T retVal)
{
	cerr << "Error: " << must;
	if (!opt.empty())
		cerr << opt;
	cerr << endl;
	return (retVal);
}

void	BitcoinExchange::parseCSV( ifstream file )
{
	string	line;
	string	key;
	float	value;
	
	getline(file, line); // Skipping the first line
	while(getline(file, line)) {
		key = line.substr(0, KEY_LENGTH);
		try {
			value = std::stof((line.erase(0, KEY_LENGTH + 1)));
		} catch (std::exception &e) {
			cout << e.what() << endl;
		}
		_map.insert(std::make_pair(key, value));
	}
	// printMap(_map);
	file.close();
}

// 3. **Input Line Format**: 
	// Each line in the input file must use the following format: `"date | value"`.
// 4. **Date Format**:
	// A valid date will always be in the following format: `Year-Month-Day`.
// 5. **Value Range**: 
	// A valid value must be either a float or a positive integer, between 0 and 1000.

/**
 * @brief 
 * 
 * @note This function can be simplified if the key is a string in _map
 * I wouldn't need to convert the string to an int
 * Here I could use the modolu 100 to cut away the last 2 digits
 */
bool	BitcoinExchange::checkValidRange(const string& date, int type)
{
	string	line;
	
	if (type == MONTH) {
		line = date.substr(date.find_first_of("-") + 1, 2);
		if (atoi(line.c_str()) > 12)
			return (false);
	}
	else {
		line = date.substr(date.find_last_of("-") + 1, 2);
		if (atoi(line.c_str()) > 31)
			return (false);
	}
	return (true);
}

/**
 * @brief 
 * 
 * @note This function could be optimised if the key of the map would be a int
 * Then I wouldn't have to convert the string  to an int to compare
 */
bool	BitcoinExchange::checkInputFile( string &line )
{
	int		cnt = 0;
	
	_date = line.substr(0, CHECK_PIPE - 1);
	if (_date.size() != 10)
		return (this->printErr("bad date format " , _date, false));
	if (std::stoi(_date) < std::stoi(_map.begin()->first))
		return (this->printErr("Date precedes first entry " , _date, false));
	string::iterator it = _date.begin();
	while (isdigit(*it) || *it == '-')
	{
		if (*it == '-')
			cnt++;
		it++;
	}
	if (it != _date.end() || cnt != 2)
		return (this->printErr("bad date format " , _date, false));
	if (!checkValidRange(_date, MONTH) || !checkValidRange(_date, DAY))
		return (this->printErr("bad date format " , _date, false));
	try {
		line.erase(0, line.find('|') + 1);
		line.erase(std::remove_if(line.begin(), line.end(), (int(*)(int))std::isspace), line.end());
		_value = std::stof(line);
		if (_value < 0)
				return (this->printErr("not a positive number.", "", false));
		if (_value > 1000)
				return (this->printErr("too large a number.", "", false));
		} catch (std::invalid_argument&) {
				return (this->printErr("Invalid input. Not a number.", "", false));
		} catch (std::out_of_range&) {
				return (this->printErr("Number out of range for float.", "", false));
		}
	return (true);
}

ifstream BitcoinExchange::prepFile(const string& filename)
{
	std::ifstream file(filename);
	if (!file.is_open() || file.peek() == std::ifstream::traits_type::eof())
		exit(this->printErr("Erroneous file.", "", 1));
	return (file);
}

/**
 * @brief 
 * 
 * @note This function could be optimised if the key of the map would be a int
 * Then I wouldn't have to convert it to an int and vice versa
 */
void	BitcoinExchange::lookupExchangeRate( void )
{
	int		dayValue;
	int		pos;
	string	temp;
	string	dup(_date);
	
	std::map<string, float>::iterator it = _map.find(dup);
	while (it == _map.end()) {
		pos = dup.find_last_of('-') + 1;
		temp = dup.substr(pos);
		dayValue = std::stoi(temp);
		if (dayValue != 0)
			dayValue--;
		if (dayValue < 10) {
			std::ostringstream oss;
			oss << std::setw(2) << std::setfill('0') << dayValue;
			dup.replace(pos, temp.length(), oss.str());
		} else 
			dup.replace(pos, temp.length(), std::to_string(dayValue));
		it = _map.find(dup);
	}
	_csvValue = it->second;
}

void	BitcoinExchange::calcValue( ifstream file )
{
	string	line;
	int		i;

	
	getline(file, line); // Skip first line
	while (getline(file, line)) {
		if (line.empty())
			continue;
		for (i = 0; isspace(line[i]); i++)
			i++;
		line.erase(0, i); // Deleting whitespace before data
		if (line.find("|") != std::string::npos) {
			if (!this->checkInputFile(line))
				continue ;
			this->lookupExchangeRate();
			cout << _date << " => " <<  _value << " = " << _csvValue * _value << endl;
		} else 
		 	this->printErr("bad input => ", line, 0);
	}
}

