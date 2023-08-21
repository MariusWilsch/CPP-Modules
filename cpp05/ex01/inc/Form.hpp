/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:54:56 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 12:02:08 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;
	public:

	/*			Class Functions			*/
	
		Form(void);
		Form(const std::string name, int gradeSign, int gradeExec);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form(void);
	
	/*			Getter/Setter			*/
	
		std::string			getName(void) const;
		bool				getSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;

	/*			Member Functions		*/
	
		void				beSigned(const Bureaucrat& src);
};

#endif