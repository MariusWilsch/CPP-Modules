/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:35:09 by verdant           #+#    #+#             */
/*   Updated: 2023/08/08 11:21:29 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <list>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class RPN {
	private:
		std::stack<int> _rpnStack;
		std::list<char> _tempList;
	public:
	
	/* Orthodox Canonical Form */
	
				RPN();
				~RPN();
				RPN( const RPN& src);
				RPN& operator=(const RPN& src);

	/* Member Functions */
	
	bool		isValidToken(string str, int len);
	void		exeRPN( void );
	void		applyOperation( char mathOperator );
};