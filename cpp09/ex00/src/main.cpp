/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:07:09 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 16:09:49 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int		main( int argc, char **argv)
{
	if (argc != 2)
	{ // Build a error function
		cout << "Usage: ./btc input.txt" << endl;
		return (1);
	}
	BitcoinExchange btc;

	btc.parseCSV(btc.prepFile("assets/data.csv"));
	btc.calcValue(btc.prepFile(argv[1]));	
}
