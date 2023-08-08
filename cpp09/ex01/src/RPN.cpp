/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:35:10 by verdant           #+#    #+#             */
/*   Updated: 2023/08/08 11:21:57 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*		Orthodox Canonical Form		*/

RPN::RPN( void ) {};

RPN::~RPN( void ) {};

RPN::RPN( const RPN& src) : _rpnStack(src._rpnStack) {};

RPN& RPN::operator=(const RPN& src) {
	if (this == &src )
		return (*this);
	_rpnStack = src._rpnStack;
	return (*this);
}

/*			Member Functions		*/

bool	RPN::isValidToken(string token, int len)
{
	string				validTokens = "0123456789-+/*";
	
	for (int i = 0; i < token.length(); i++) {
		if (validTokens.find(token[i]) == string::npos)
			return (false); 
		_tempList.push_back(token[i]);
	}
	return (true);
}

void	RPN::applyOperation( char mathOperator )
{
	int	num1, num2;

	num1 = _rpnStack.top();
	_rpnStack.pop();
	num2 = _rpnStack.top();
	_rpnStack.pop();
	
	switch (mathOperator)
	{
	case '-':
		_rpnStack.push(num2 - num1);
		break ;
	case '+':
		_rpnStack.push(num2 + num1);
		break ;
	case '*':
		_rpnStack.push(num2 * num1);
		break ;
	case '/':
		_rpnStack.push(num2 / num1);
		break;
	default:
		break;
	}	
}

void	RPN::exeRPN( void )
{
	std::list<char>::iterator it;

	for (it = _tempList.begin(); it != _tempList.end(); it++)
	{
		if (isdigit(*it))
			_rpnStack.push(*it  - '0');
		else {
			if (_rpnStack.size() < 2) {
				cerr << "Not enough digits for operand: " << *it << endl;
				exit(1);
			} // TODO: Replace for err function
			applyOperation(*it);
		}
	} 
	if (_rpnStack.size() != 1) {
		cerr << "Too many operands" << endl;
		exit(1);
	} else 
		cout << _rpnStack.top() << endl;
}
