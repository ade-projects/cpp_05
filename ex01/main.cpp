/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:30:06 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/18 15:46:38 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

int	main()
{
	Bureaucrat president("President", 1);
	std::cout << "Instance's attributes: " << president << std::endl;
	std::cout << std::endl;

	Bureaucrat director("Director", 50);
	std::cout << "Instance's attributes: " << director << std::endl;
	std::cout << std::endl;

	Bureaucrat maggot("Maggot", 150);
	std::cout << "Instance's attributes: " << maggot << std::endl;
	std::cout << std::endl;
	
	try
	{
		Form low_form("Low Form", 151, 151);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form high_form("High Form", 0, 0);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	Form invoice("Invoice", 5, 5);
	std::cout << "Instance's attributes: \n" << invoice << std::endl;
	std::cout << std::endl;

	Form expenses("Expenses", 50, 50);
	std::cout << "Instance's attributes: \n" << expenses << std::endl;
	std::cout << std::endl;

	Form requests("Requests", 100, 100);
	std::cout << "Instance's attributes: \n" << requests << std::endl;
	std::cout << std::endl;

	maggot.signForm(invoice);
	maggot.signForm(expenses);
	maggot.signForm(requests);
	std::cout << std::endl;

	director.signForm(invoice);
	std::cout << std::endl;

	director.signForm(expenses);
	std::cout << "Instance's attributes are now: \n" << expenses << std::endl;
	std::cout << std::endl;

	director.signForm(requests);
	std::cout << "Instance's attributes are now: \n" << requests << std::endl;
	std::cout << std::endl;

	std::cout << "Cleaning: " << std::endl;

	return (0);
}
