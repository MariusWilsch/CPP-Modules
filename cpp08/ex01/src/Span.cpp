/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:04:16 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 15:40:04 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _n(0) {};

Span::Span(unsigned int n) : _n(n) 
{
	if (n == 0)
		throw std::exception();
}

Span::Span(const Span &other) : _n(other._n), _set(other._set) {}

Span::~Span() {};

Span& Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	_n = other._n;
	_set = other._set;
	return (*this);
}

void	Span::printAll(void)
{
	std::set<int>::iterator it =_set.begin();
	while (it != _set.end())
		std::cout << *it++ << " ";
	std::cout << std::endl;
}

void	Span::addNumber(int n)
{
	if (this->_set.size() < this->_n)
		this->_set.insert(n);
	else
		throw std::exception();
}

void	Span::addRange( std::set<int>::iterator begin, std::set<int>::iterator end)
{
	if (_set.size() + std::distance(begin, end) <= _n)
		_set.insert(begin, end);
	else
		throw std::exception();
}

void	Span::longestSpan(void)
{
	if (_set.empty() || _set.size() == 1)
		throw std::exception();
	
	std::cout << "Longest span: " << *(_set.rbegin()) - *(_set.begin()) << std::endl;
}

void	Span::shortestSpan(void)
{
	if (_set.empty() || _set.size() == 1)
		throw std::exception();
		
	int shortest = __INT_MAX__;

	std::set<int>::iterator it = _set.begin();
	std::set<int>::iterator next = _set.begin();
	next++;
	std::set<int>::iterator end = _set.end();
	
	while (next != end)
	{
		if (*next - *it < shortest)
			shortest = *next - *it;
		it++;
		next++;
	}
	std::cout << "Shortest span: " << shortest << std::endl;
}


