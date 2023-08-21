/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:19:03 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 15:39:11 by verdant          ###   ########.fr       */
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

// int main() {
//     Span sp(10);

//     // Test 1: Add numbers using addNumber()
//     for (int i = 1; i <= 5; i++) {
//         sp.addNumber(i);
//     }

//     // Test 2: Add a range of numbers using addRange()
//     std::set<int> numbers;
// 	numbers.insert(6);
// 	numbers.insert(7);
// 	numbers.insert(8);
// 	numbers.insert(9);
// 	numbers.insert(10);
//     sp.addRange(numbers.begin(), numbers.end());

//     // Test 3: Checking shortestSpan() and longestSpan()
//     sp.shortestSpan();
//     sp.longestSpan();

//     // Test 4: Exception when adding more numbers than span can handle
//     bool exceptionCaught = false;
//     try {
//         sp.addNumber(11);
//     } catch (const std::exception& e) {
//         exceptionCaught = true;
//     }

//     std::cout << "Exception caught when overfilling: " << (exceptionCaught ? "Yes" : "No") << std::endl;

//     // Test 5: Behavior with insufficient numbers
//     Span sp2(10);
//     sp2.addNumber(1);

//     bool exceptionCaughtShortest = false;
//     bool exceptionCaughtLongest = false;
//     try {
//         sp2.shortestSpan();
//     } catch (const std::exception& e) {
//         exceptionCaughtShortest = true;
//     }

//     try {
//         sp2.longestSpan();
//     } catch (const std::exception& e) {
//         exceptionCaughtLongest = true;
//     }

//     std::cout << "Exception caught when insufficient numbers (shortest): " << (exceptionCaughtShortest ? "Yes" : "No") << std::endl;
//     std::cout << "Exception caught when insufficient numbers (longest): " << (exceptionCaughtLongest ? "Yes" : "No") << std::endl;

//     return 0;
// }


