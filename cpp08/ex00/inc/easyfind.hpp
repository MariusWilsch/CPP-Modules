/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:06:31 by verdant           #+#    #+#             */
/*   Updated: 2023/07/31 15:29:10 by verdant          ###   ########.fr       */
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
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::exception();
	return *it;
}