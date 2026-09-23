/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:24:54 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/23 19:52:05 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern& Intern::operator=(const Intern& src)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)src;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeShrub(std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobot(std::string target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresident(std::string target) const
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string target) const
{
	std::string formNames[3] = {"shrubbery_creation", "robotomy_request", "presidential_pardon"};

	AForm* (Intern::*formCreators[3])(std::string target) const
		= {&Intern::makeShrub, &Intern::makeRobot, &Intern::makePresident};
	
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*formCreators[i])(target));
		}
	}

	std::cout << "Intern can't create " << formName << " because it doesn't exist." << std::endl;
	return (NULL);
}
