/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:41:35 by verdant           #+#    #+#             */
/*   Updated: 2023/07/31 14:49:44 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T> void print(T &a) {
	std::cout << a << std::endl;
}

template <typename T> void iter(T arr[], int len, void (*print)(T&)) {
	for (int i = 0; i < len; i++)
		print(arr[i]);
}