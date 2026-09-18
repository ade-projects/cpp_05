/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 11:12:14 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/18 13:36:29 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Form's name"), _isSigned(false), _signingGrade(150), _executingGrade(150) 
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, unsigned int signingGrade, unsigned int executingGrade)
	: _name(name), _isSigned(false), _signingGrade(signingGrade), _executingGrade(executingGrade)
{
	std::cout << "Form parameterized constructor called for " << this->_name << std::endl;
	if (signingGrade < 1 || executingGrade < 1)
		throw Form::GradeTooHighException();
	if (signingGrade > 150 || executingGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src) : _name(src.getName()), _isSigned(src.getSigned()), _signingGrade(src.getSigningGrade()), _executingGrade(src.getExecutingGrade())
{
	std::cout << "Form copy constructor called: cloning from " << src.getName() << std::endl;
}

Form& Form::operator=(const Form& src)
{
	std::cout << "Form copy assignment operator called: copying attributes from " << src.getName() << std::endl;
	if (this != &src)
		this->_isSigned = src.getSigned();
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called for " << this->_name << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_isSigned);
}

unsigned int Form::getSigningGrade() const
{
	return (this->_signingGrade);
}

unsigned int Form::getExecutingGrade() const
{
	return (this->_executingGrade);
}

void Form::beSigned(const Bureaucrat& src)
{
	if (src.getGrade() <= this->_signingGrade)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form's name: " << form.getName() << "\n"
		<< "Status: " << (form.getSigned() ? "signed" : "not signed") << "\n"
		<< "Signing grade needed: " << form.getSigningGrade() << "\n"
		<< "Executing grade needed: " << form.getExecutingGrade();
	return (os);
}
