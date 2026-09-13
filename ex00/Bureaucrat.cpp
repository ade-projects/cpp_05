/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:27:24 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/13 18:15:10 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLow









		





	std::cout << "Parameterized constructor called for " << this->_name << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << "Copy constructor called: cloning from " << src._name << std::endl;	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
	{
		this->_grade = src.getGrade();
	}
	std::cout << "Copy assignment operator called: copy attributes from " << src._name << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called for " << this->_name << std::endl;
}
