/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:25:15 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 15:12:09 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;
	

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	
	try
	{
		std::cout << "vector: " << easyFind(v, 1) << std::endl;
		std::cout << "list: " << easyFind(l, 2) << std::endl;
		std::cout << "deque: " << easyFind(d, 3) << std::endl;
		std::cout << "vector: " << easyFind(v, 42) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	return 0;
}