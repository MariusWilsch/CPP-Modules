/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:07:09 by verdant           #+#    #+#             */
/*   Updated: 2023/10/11 13:36:32 by mwilsch          ###   ########.fr       */
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


	btc.parseCSV("assets/data.csv");
	btc.calcValue(argv[1]);	
}
