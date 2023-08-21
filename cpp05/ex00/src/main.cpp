/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:25:36 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 08:42:05 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src) {
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return os;
}

int main(void)
{
	try {
		Bureaucrat a("Dirk", 1);
		std::cout << a;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Dirk", 200);
		std::cout << b;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat c("Dirk", 150);
		std::cout << c;
		std::cout << "Decrementing grade..." << std::endl;
		c.decGrade();
		std::cout << c;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat d("Dirk", 1);
		std::cout << d;
		std::cout << "Incrementing grade..." << std::endl;
		d.incGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}