/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:19:03 by verdant           #+#    #+#             */
/*   Updated: 2023/08/01 10:49:41 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Shortest span

#include "Span.hpp"



int	main( void )
{
	std::cout << "---- TEST 0  -----" << std::endl;

	Span sp = Span( 5 );

	sp.addNumber( 6 );
	sp.addNumber( 3 );
	sp.addNumber( 9 );
	sp.addNumber( 17 );
	sp.addNumber( 11 );

	sp.longestSpan();
	sp.shortestSpan();

	std::cout << "---- TEST 1  -----" << std::endl;
	std::set<int> set;
	std::srand(std::time(NULL));

	while (set.size() < 10000)
		set.insert(std::rand());
	Span sp1 = Span(10000);
	sp1.addRange(set.begin(), set.end());
	sp1.shortestSpan();
	sp1.longestSpan();
}