/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:28:39 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/14 13:06:28 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		}

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		}

		std::string getName() const;
		unsigned int getGrade() const;
		void incrementGrade();
		void decrementGrade();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
