/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:42:09 by verdant           #+#    #+#             */
/*   Updated: 2023/08/21 12:26:05 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>

# include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::string;

class Bureaucrat;

class GradeNotSigned : public std::exception
{
	public:
		const char* what() const throw() {
			return ("Form isn't signed");
		}
};

class AForm
{
	private:
		const std::string	_name;
		bool							_signed;
		const int					_gradeSign;
		const int					_gradeExec;
	public:
	/*			Orthodox canonical  form			*/

		AForm(void);
		AForm(const std::string name, int gradeSign, int gradeExec);
		AForm(const AForm& src);
		AForm& operator=(const AForm& src);
		virtual ~AForm(void) = 0;
	
	/*			Getters			*/	
	
		std::string			getName(void) const;
		bool				getSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;

	/*		Member Functions		*/
	
		void				beSigned(const Bureaucrat& src);
		void				signForm(const AForm& src);
		void				checkBureaucrat(const Bureaucrat& src) const;
		virtual void		execute(const Bureaucrat& executor) const = 0;
};

#endif 