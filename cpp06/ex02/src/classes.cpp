/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:24:15 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 13:05:47 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"

Base::~Base(void) {};

void	turnToVoid(Base *p)
{
	(void)p;
}



Base *generate(void)
{
	std::srand(std::time(NULL));
	int	rand = std::rand() % 3;
	std::cout << "Random number: " << rand << std::endl;
	if (rand == 0)
		return (static_cast<Base *>(new A));
	if (rand == 1)
		return (static_cast<Base *>(new B));
	return (static_cast<Base *>(new C));
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base &p)
{
	try {
		A& a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		turnToVoid(&a);
	} catch (const std::exception& e) {}
	try {
		B& b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		turnToVoid(&b);
	} catch (const std::exception& e) {}
	try {
		C& c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		turnToVoid(&c);
	} catch (const std::exception& e) {}
}

// void    identify( Base& p ) {
//     try {
//         A& a = dynamic_cast< A& >( p );
//         std::cout << "A" << std::endl;
//         (void)a;
//     } catch(const std::exception& e) {}
//     try {
//         B& b = dynamic_cast< B& >( p );
//         std::cout << "B" << std::endl;
//         (void)b;
//     } catch( const std::exception& e ) {}
//     try {
//         C& c = dynamic_cast< C& >( p );
//         std::cout << "C" << std::endl;
//         (void)c;
//     } catch( const std::exception& e ) {}
// }