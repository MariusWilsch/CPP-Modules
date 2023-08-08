/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:58:47 by verdant           #+#    #+#             */
/*   Updated: 2023/08/08 12:40:13 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main (int argc, char **argv)
{
	if (argc < 2)
		return 0;
	try {
		SortContainers sort(argv);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
