/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:18:29 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/19 19:12:47 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <exception>

int	main()
{
	std::cout << "ShrubberyCreationForm tests: \n" << std::endl;

	Bureaucrat high("High", 42);
	Bureaucrat low("Low", 150);
	ShrubberyCreationForm shrub("home");
	std::cout << std::endl;

	std::cout << "Attributes before signing:" << std::endl;
	std::cout << shrub << "\n" << std::endl;
		
	std::cout << "Trying executing unsigned form:" << std::endl;
	try
	{
		shrub.execute(high);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Trying with bureaucrat too low to sign:" << std::endl;
	low.signForm(shrub);
	std::cout << std::endl;
		
	std::cout << "Trying with high enough to sign:" << std::endl;
	high.signForm(shrub);
	std::cout << std::endl;

	std::cout << "Attributes after signing: " << std::endl;
	std::cout << shrub << std::endl;
	std::cout << std::endl;

	std::cout << "Trying to low to execute:" << std::endl;
	try
	{
		shrub.execute(low);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Trying high enough to execute:" << std::endl;
	try
	{
		shrub.execute(high);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "Execution done! \n" << std::endl;
	
	std::cout << "-- Cleaning: --\n" << std::endl;

	return (0);
}
