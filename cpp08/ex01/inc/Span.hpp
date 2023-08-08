/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:01:12 by verdant           #+#    #+#             */
/*   Updated: 2023/08/02 13:13:21 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <ctime>



class Span
{
private:
	unsigned int _n;
	std::set<int> _set;
public:
	Span(void);
	Span(unsigned int n);
	Span(const Span &other);
	Span& operator=(const Span &other);
	~Span();

	void	addNumber(int n);
	void	addRange(std::set<int>::iterator begin, std::set<int>::iterator end);
	void	longestSpan(void);
	void	shortestSpan(void);
	void	printAll(void);
};