/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 11:11:22 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/18 12:44:12 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string		_name;
		bool					_isSigned;
		const unsigned int		_signingGrade;
		const unsigned int		_executingGrade;

	public:
		Form();
		Form(std::string name, unsigned int signingGrade, unsigned int executingGrade);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public: 
				virtual const char* what() const throw();
		};
		
		std::string getName() const;
		bool getSigned() const;
		unsigned int getSigningGrade() const;
		unsigned int getExecutingGrade() const;
	
		void beSigned(const Bureaucrat& src);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
