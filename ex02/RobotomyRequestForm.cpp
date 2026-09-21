/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:43:01 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/21 13:41:20 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("Default_target")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm parameterized constructor called for " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm(src), _target(src._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecutingGrade())
		throw AForm::GradeTooLowException();

	std::cout << "grrrrr!! clunk!! vrrrr... plop!!-" << std::endl;

	srand(time(NULL));
	if (rand() % 2 == 0)
	{
		std::cout << this->_target << " has been successfully robotomized." << std::endl;
	}
	else
	{
		std::cout << "Robotomyu on " << this->_target << " failed." << std::endl;
	}
}
