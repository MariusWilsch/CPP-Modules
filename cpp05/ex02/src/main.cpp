/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:47:01 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 12:28:31 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return os;
}

std::ostream& operator<<(std::ostream& os, const ShurbberyCreationForm& rhs)
{
	os << rhs.getName() << ", form gradeSign " << rhs.getGradeSign() <<", form gradeExce" << rhs.getGradeExec() << ".";
	return os;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& rhs)
{
	os << rhs.getName() << ", form gradeSign " << rhs.getGradeSign() <<", form gradeExce" << rhs.getGradeExec() << ".";
	return os;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& rhs)
{
	os << rhs.getName() << ", form gradeSign " << rhs.getGradeSign() <<", form gradeExce" << rhs.getGradeExec() << ".";
	return os;
}

/*			Burecrat execute Test			*/

// int main(void)
// {
// 	Bureaucrat bob("Bob", 2);
// 	ShurbberyCreationForm shrub("Shrub");
// 	cout << "--- Objects created ---" << endl << endl;
// 	cout << "Bob's Score: " << bob.getGrade() << " < Mercel's Score: " << shrub.getGradeSign() << endl;
// 	try {
// 		shrub.beSigned(bob);
// 		bob.executeForm(shrub);
// 	} catch (std::exception &e) {
// 		cout << e.what() << endl;
// 	}
// }

/*			PresidentalPardonForm Test			*/

int main(void)
{
	Bureaucrat bob("Bob", 3);
	PresidentialPardonForm mercel("Mercel");
	cout << "--- Objects created ---" << endl << endl;
	cout << "Bob's Score: " << bob.getGrade() << " < Mercel's Score: " << mercel.getGradeExec() << endl;
	try {
		mercel.beSigned(bob);
	} catch (std::exception &e) {
		cout << e.what() << endl;
	}
	try {
		mercel.execute(bob);
	} catch (std::exception &e) {
		cout << e.what() << endl;	
	}
}

/*			RobotomyRequestForm Test			*/

// int main(void)
// {
// 	Bureaucrat bob("Bob", 2);
// 	RobotomyRequestForm robo("Robi");
// 	cout << "--- Objects created ---" << endl << endl;
// 	cout << "Bob's Score: " << bob.getGrade() << " < Robo's Score: " << robo.getGradeExec() << endl;
// 	try {
// 		robo.beSigned(bob);
// 	} catch (std::exception &e) {
// 		cout << e.what() << endl;
// 	}
// 	try {
// 		robo.execute(bob);
// 	} catch (std::exception &e) {
// 		cout << e.what() << endl;	
// 	}
// }

/*			ShurbberyCreationForm Test			*/

// int main(void)
// {
// 	Bureaucrat bob("Bob", 10);
// 	ShurbberyCreationForm a("Tree");
//	cout << "--- Objects created ---" << endl << endl;
// 	cout << "Bob's Score: " << bob.getGrade() << " < Tree's Score: " << a.getGradeExec() << endl;
// 	try {
// 		a.beSigned(bob);
// 	} catch (std::exception &e) {
// 		cout << e.what() << endl;
// 	}
// 	a.signForm(a);
// 	try {
// 		a.execute(bob);
// 	} catch (std::exception &e) {
// 		cout << e.what() << endl;
// 	}
// }
