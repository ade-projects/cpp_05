/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:18:29 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/21 11:07:59 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <exception>

int	main()
{
	std::cout << "\n-- ShrubberyCreationForm tests: --\n" << std::endl;

	Bureaucrat high("High_Level", 42);
	Bureaucrat low("Low_Level", 150);
	ShrubberyCreationForm shrub("Shrub");
	std::cout << std::endl;

	std::cout << "Attributes before signing:" << std::endl;
	std::cout << shrub << "\n" << std::endl;
		
	std::cout << "High_Level trying executing unsigned form:" << std::endl;
	try
	{
		shrub.execute(high);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Low_Level trying to sign:" << std::endl;
	low.signForm(shrub);
	std::cout << std::endl;
		
	std::cout << "high_Level trying to sign:" << std::endl;
	high.signForm(shrub);
	std::cout << std::endl;

	std::cout << "Attributes after signing: " << std::endl;
	std::cout << shrub << std::endl;
	std::cout << std::endl;

	
	std::cout << "Low_Level trying to execute:" << std::endl;
	low.executeForm(shrub);	
	std::cout << std::endl;

	std::cout << "High_Level trying to execute:" << std::endl;
	high.executeForm(shrub);		
	std::cout << std::endl;

	std::cout << "-- Cleaning: --\n" << std::endl;

	return (0);
}
