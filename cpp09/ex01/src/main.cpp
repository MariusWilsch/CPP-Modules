/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:35:12 by verdant           #+#    #+#             */
/*   Updated: 2023/08/08 11:24:53 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int		main( int argc, char** argv )
{
	if (argc != 2 || argv[1][0] == '\0') {
		cerr << "Usage ./RPN \"expression here\"";
		return (1);
	} // TODO: replace for err function
	
	RPN rpn;
	std::istringstream ss(argv[1]);
	string token;
	while (std::getline(ss, token, ' '))
	{
		if (!rpn.isValidToken(token, token.length())) {
			cerr << "Invalid token: " << token << endl;
			return (1);
		} // TODO: replace for err function
	}
	rpn.exeRPN();
}