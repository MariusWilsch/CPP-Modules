/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:58:47 by verdant           #+#    #+#             */
/*   Updated: 2023/10/11 07:58:01 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Use this for testing `jot -r 3000 1 1000 | tr '\n' ' '` to generate a random list of numbers

int	main (int argc, char **argv)
{
	if (argc < 2)
		return 0;
	try {
			PmergeMe pm(argv);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

