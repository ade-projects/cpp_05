/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:27:24 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/20 15:25:12 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default_Name"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat parameterized constructor called for " << this->_name << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << "Bureaucrat copy constructor called: cloning from " << src.getName() << std::endl;	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << "Bureaucrat copy assignment operator called: copying attributes from " << src.getName() << std::endl;
	if (this != &src)
		this->_grade = src.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called for " << this->_name << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

void Bureaucrat::signForm(Form& src)
{
	if (src.getSigned())
	{
		std::cout << this->_name << " couldn't sign " << src.getName() << " because this form is already signed" << std::endl;
		return ;
	}
	try
	{
		src.beSigned(*this);
		std::cout << this->_name << " signed " << src.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << src.getName() << " because " << e.what() << std::endl;
	}
}
