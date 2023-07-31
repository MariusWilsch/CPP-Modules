/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:11:59 by verdant           #+#    #+#             */
/*   Updated: 2023/07/31 14:35:45 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T> void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T min(T &a, T &b) {
	if (a == b)
		return b;
	return (a < b ? a : b);
}

template <typename T> T max(T &a, T&b)
{
	if (a == b)
		return b;
	return (a > b ? a : b);
}	
