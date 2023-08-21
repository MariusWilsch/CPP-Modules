/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:16:15 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 12:07:11 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

std::ostream& operator<<(std::ostream& os, const Form& src)
{
	os << src.getName() << " is signed: " << std::boolalpha << src.getSigned() << std::endl;
	return os;
}

int main(void)
{
	try {	
		Bureaucrat b("Bob", 2);
		Form f("Form", 2, 1);
		f.beSigned(b);
		b.signForm(f);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// try {
	// 	Bureaucrat a("Ada", 2);
	// 	Form 			f("Form", 20, 1);
	// 	b.signForm(f);
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }
	
	// try {
	// 	Bureaucrat c("Claud", 20);
	// 	Form 			f("Form", 20, 1);
	// 	f.beSigned(c);
	// 	b.signForm(f);
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }
	
	return (EXIT_SUCCESS);
}