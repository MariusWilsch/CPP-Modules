/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:03:30 by verdant           #+#    #+#             */
/*   Updated: 2023/07/31 12:15:57 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

struct Data
{
	int n;
	Data(int n);
};

class Serializer
{
	public:
		Serializer(void);
		Serializer(const Serializer &src);
		~Serializer(void);
		Serializer &operator=(const Serializer &rhs);

		static uintptr_t serialize(Data *ptr);
		static Data		*deserialize(uintptr_t raw);
};