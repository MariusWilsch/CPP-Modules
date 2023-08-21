/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:57:56 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 12:06:51 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("Default"), _signed(false), _gradeSign(150), _gradeExec(150) {
	std::cout << "Default constructor called" << std::endl;
}

Form::Form ( const std::string name, int gradeSign, int gradeExec ) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	if (this->_gradeSign < 1 || this->_gradeExec < 1)
		throw GradeTooHighException();
	if (this->_gradeSign > 150 || this->_gradeExec > 150)
		throw GradeTooLowException();
	std::cout << "Parametric constructor called" << std::endl;
}

Form::Form( const Form & src ) : _name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {
	std::cout << "Copy constructor called" << std::endl;
}

Form &	Form::operator=( const Form & rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs ) {
		this->_signed = rhs._signed;
	}
	return *this;
}

Form::~Form( void ) {
	std::cout << "Destructor called" << std::endl;
}

std::string Form::getName(void) const {
	return this->_name;
}

bool Form::getSigned(void) const {
	return this->_signed;
}

int Form::getGradeSign(void) const {
	return this->_gradeSign;
}

int Form::getGradeExec(void) const {
	return this->_gradeExec;
}

void	Form::beSigned(const Bureaucrat& src)
{
	if (src.getGrade() <= getGradeSign())
		_signed = true;
	else 
		throw GradeTooLowException();
}


