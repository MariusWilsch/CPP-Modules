/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:25:16 by verdant           #+#    #+#             */
/*   Updated: 2023/05/31 16:37:19 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>

# include "AForm.hpp"
class AForm;

class GradeTooHighException : public std::exception {
public:
		const char* what() const throw() {
				return "Grade too high";
		}
};

class GradeTooLowException : public std::exception {
public:
		const char* what() const throw() {
				return "Grade too low";
		}
};

class Bureaucrat {
	private:
		const std::string	_name;
		int								_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat(void);
		int	getGrade(void) const;
		std::string	getName(void) const;
		void	incGrade(void);
		void	decGrade(void);
		void executeForm(const AForm& form);
};



#endif