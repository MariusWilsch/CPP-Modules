/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:43:53 by verdant           #+#    #+#             */
/*   Updated: 2023/10/02 12:23:11 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int		arr[] = {1, 2, 3, 4, 5};
	float	arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char	arr3[] = {'a', 'b', 'c', 'd', 'e'};

	iter(arr, 5, print);
	iter(arr2, 5, print);
	iter(arr3, 5, print);
	return (0);
}

