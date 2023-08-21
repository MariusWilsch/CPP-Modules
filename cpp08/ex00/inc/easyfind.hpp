/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:06:31 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 15:06:49 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <deque>



template <typename T> int easyFind(T &container, int n)
{
	// std::find is a STL function that returns an iterator to the first element in the range [first,last) that compares equal to val.
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::exception();
	return *it;
}