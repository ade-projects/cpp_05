/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:18:29 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/21 13:49:46 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <exception>

int	main()
{
	std::cout << "\n-- Bureaucrats tests: --\n" << std::endl;

	Bureaucrat president("President", 1);
	Bureaucrat director("Director", 50);
	Bureaucrat newbie("Newbie", 150);

	std::cout << "\n-- ShrubberyCreationForm tests: --\n" << std::endl;

	ShrubberyCreationForm shrub("Shrub");
	std::cout << std::endl;

	std::cout << "Attributes before signing:" << std::endl;
	std::cout << shrub << "\n" << std::endl;
		
	std::cout << "Director trying executing unsigned form:" << std::endl;
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
	std::cout << std::endl;

	std::cout << "\n-- RobotomyRequestForm tests: --\n" << std::endl;

	RobotomyRequestForm robot("Robot");





	std::cout << "-- Cleaning: --\n" << std::endl;

	return (0);
}
