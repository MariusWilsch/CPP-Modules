/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:07:29 by verdant           #+#    #+#             */
/*   Updated: 2023/07/31 12:16:20 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/**
 * @brief main entry
 * 
 * @return If the program pints same pointer, it works.
 */
int	main(void)
{
	Data		data(42);
	Data		*original_ptr = &data;
	uintptr_t	raw = Serializer::serialize(original_ptr);
	Data		*procssed_ptr = Serializer::deserialize(raw);
	
	if (original_ptr == procssed_ptr)
		std::cout << "Same pointer" << std::endl;
	else
		std::cout << "Different pointer" << std::endl;
}