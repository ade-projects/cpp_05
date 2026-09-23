/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:18:29 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/23 17:00:22 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

int	main()
{
	srand(time(NULL)); //applied in main rather than Robotomy form to test randomness

	std::cout << "\n-- Bureaucrats tests: --\n" << std::endl;

	Bureaucrat president("President", 1);
	Bureaucrat director("Director", 50);
	Bureaucrat newbie("Newbie", 150);


	std::cout << "\n-- ShrubberyCreationForm tests: --\n" << std::endl;

	ShrubberyCreationForm shrub("Garden");
	std::cout << std::endl;

	std::cout << "Attributes before signing:" << std::endl;
	std::cout << shrub << "\n" << std::endl;
		
	std::cout << "Director trying to execute unsigned form:" << std::endl;
	try
	{
		shrub.execute(director);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Newbie trying to sign:" << std::endl;
	newbie.signForm(shrub);
	std::cout << "Director trying to sign:" << std::endl;
	director.signForm(shrub);
	std::cout << std::endl;

	std::cout << "Attributes after signing: " << std::endl;
	std::cout << shrub << std::endl;
	std::cout << std::endl;

	std::cout << "Newbie trying to execute:" << std::endl;
	newbie.executeForm(shrub);
	std::cout << "Director trying to execute:" << std::endl;
	director.executeForm(shrub);		


	std::cout << "\n-- RobotomyRequestForm tests: --\n" << std::endl;

	RobotomyRequestForm robot("Hal");
	std::cout << std::endl;

	director.signForm(robot);
	director.executeForm(robot);
	std::cout << "\nTesting randomness:" << std::endl;
	president.executeForm(robot);
	president.executeForm(robot);
	president.executeForm(robot);
	president.executeForm(robot);
	president.executeForm(robot);
	president.executeForm(robot);
	president.executeForm(robot);
	president.executeForm(robot);
	president.executeForm(robot);
	president.executeForm(robot);
	
	std::cout << "\n-- PresidentialPardonForm tests: --\n" << std::endl;

	PresidentialPardonForm pardon("TheBoss");
	std::cout << std::endl;

	president.executeForm(pardon);
	std::cout << std::endl;
	
	director.signForm(pardon);
	std::cout << std::endl;

	president.signForm(pardon);
	std::cout << std::endl;

	president.executeForm(pardon);
	std::cout << std::endl;

	std::cout << "-- Cleaning: --\n" << std::endl;

	return (0);
}
