/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:26:43 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 08:42:17 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {

	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << std::endl;
	std::cout << "Parametric constructor called" << std::endl;
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	std::cout << "Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Destructor called" << std::endl;
}

int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

std::string Bureaucrat::getName(void) const {
	return (this->_name);
}
void Bureaucrat::incGrade(void)
{
	if (this->_grade - 1 < 1) {
		throw GradeTooHighException();
	}
	this->_grade--;
}

void	Bureaucrat::decGrade(void) {
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char* GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* GradeTooLowException::what() const throw() {
	return "Grade too low";
}
