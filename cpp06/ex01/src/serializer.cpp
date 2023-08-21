/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:04:52 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 12:49:27 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &src) {
	*this = src;
}

Serializer::~Serializer(void) {}

Serializer &Serializer::operator=(const Serializer &rhs) {
	if (this != &rhs) {
		(void)rhs;
	}
	return (*this);
}

Data::Data(int n) : n(n) {};

/*			Member Functions			*/

uintptr_t Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}