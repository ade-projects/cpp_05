/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 11:11:22 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/19 18:35:04 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string		_name;
		bool					_isSigned;
		const unsigned int		_signingGrade;
		const unsigned int		_executingGrade;

	public:
		AForm();
		AForm(std::string name, unsigned int signingGrade, unsigned int executingGrade);
		AForm(const AForm& src);
		AForm& operator=(const AForm& src);
		virtual ~AForm();

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
		
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		std::string getName() const;
		bool getSigned() const;
		unsigned int getSigningGrade() const;
		unsigned int getExecutingGrade() const;
	
		void beSigned(const Bureaucrat& src);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& aform);

#endif
