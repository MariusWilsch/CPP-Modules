/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:25:16 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 12:04:06 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include "Form.hpp"

class Form;

class GradeTooHighException : public std::exception {
public:
	const char* what() const throw();
};

class GradeTooLowException : public std::exception {
public:
	const char* what() const throw();
};

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
	/*			Class Functions*/
	
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat(void);
	
	/*			Getter/Setter			*/

		int	getGrade(void) const;
		std::string	getName(void) const;

	/*			Member Functions		*/
	
		void	incGrade(void);
		void	decGrade(void);
		void	signForm(const Form& src);
};



#endif