/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:13:15 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 15:43:24 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <deque>
#include <list>
#include <algorithm>
#include <iostream>

/**
 * @brief 
 * 
 * @note the variable `c` in begin() and end() is a protected member variable
 * that "adapter" classes share with which you can access the underlying container.
 * @note For std::stack the underlying container is typically a std::deque
 * 
 * @tparam T data type that will be specified in complie time
 */
template <typename T>
class MutantStack : public std::stack<T> 
{
	public:
		MutantStack( void ) {};
		~MutantStack( void ) {};
		MutantStack(const MutantStack &other) { *this = other; }
		MutantStack &operator=(const MutantStack &other) { 
			if (this == &other) 
				return *this;
			 this->c = other.c;
		}

	
		typedef typename std::deque<T>::iterator iterator;

		iterator begin() { return this->c.begin(); }
		
		iterator end() { return this->c.end(); }
};
