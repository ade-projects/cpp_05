/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 11:12:14 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/19 18:41:23 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("AForm's name"), _isSigned(false), _signingGrade(150), _executingGrade(150) 
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, unsigned int signingGrade, unsigned int executingGrade)
	: _name(name), _isSigned(false), _signingGrade(signingGrade), _executingGrade(executingGrade)
{
	std::cout << "AForm parameterized constructor called for " << this->_name << std::endl;
	if (signingGrade < 1 || executingGrade < 1)
		throw AForm::GradeTooHighException();
	if (signingGrade > 150 || executingGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src) : _name(src.getName()), _isSigned(src.getSigned()), _signingGrade(src.getSigningGrade()), _executingGrade(src.getExecutingGrade())
{
	std::cout << "AForm copy constructor called: cloning from " << src.getName() << std::endl;
}

AForm& AForm::operator=(const AForm& src)
{
	std::cout << "AForm copy assignment operator called: copying attributes from " << src.getName() << std::endl;
	if (this != &src)
		this->_isSigned = src.getSigned();
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called for " << this->_name << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_isSigned);
}

unsigned int AForm::getSigningGrade() const
{
	return (this->_signingGrade);
}

unsigned int AForm::getExecutingGrade() const
{
	return (this->_executingGrade);
}

void AForm::beSigned(const Bureaucrat& src)
{
	if (src.getGrade() <= this->_signingGrade)
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& aform)
{
	os << "Form's name: " << aform.getName() << "\n"
		<< "Status: " << (aform.getSigned() ? "signed" : "not signed") << "\n"
		<< "Signing grade needed: " << aform.getSigningGrade() << "\n"
		<< "Executing grade needed: " << aform.getExecutingGrade();
	return (os);
}
