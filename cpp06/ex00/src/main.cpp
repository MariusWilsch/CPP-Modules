/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:53:45 by verdant           #+#    #+#             */
/*   Updated: 2023/07/20 16:04:24 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/casting.hpp"


// Check what to do with when the number is out of range of the type

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	ScalarConverter::convert(argv[1]);
	return (0);
}