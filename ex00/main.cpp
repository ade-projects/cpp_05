/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:30:06 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/21 12:13:37 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "\n - Constructors and overload testing: - \n" << std::endl;

	Bureaucrat defaultBureaucrat;
	std::cout << "Instance's attributes: " << defaultBureaucrat << "\n" << std::endl;	

	Bureaucrat junior("Junior", 42);
	std::cout << "Instance's attributes: " << junior << "\n" << std::endl;
	
	Bureaucrat juniorClone(junior);
	std::cout << "Instance's attributes: " << juniorClone << "\n" << std::endl;

	defaultBureaucrat = junior;
	std::cout << "Instance's attributes: " << defaultBureaucrat << std::endl;
	std::cout << "(as _name is constant only _grade can be copied)" << std::endl; 

	std::cout << "\n---\n" << std::endl;

	std::cout << " - Exception testing: instantiation: - \n" << std::endl;

	// Uncomment next 2 lines to generate crash in program:
	// std::cout << "Trying with grade 0:" << std::endl;
	// Bureaucrat wrong_one("Wrong One", 0);

	// Uncomment next 2 lines to generate crash in program:
	// std::cout << "Trying with grade 151:" << std::endl;
	// Bureaucrat wrong_two("Wrong Two",151);

	try
	{
		std::cout << "Trying with grade 0:" << std::endl;
		Bureaucrat highLevel("High_Level", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "Trying with grade 234:" << std::endl; 
		Bureaucrat lowLevel("Low_Level", 234);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "\n---\n" << std::endl;

	std::cout << " - Getters and increment/decrement testing: - \n" << std::endl;
	
	try
	{
		Bureaucrat senior("Senior", 23);
		std::cout << "Initial " << senior.getName() << "'s grade is: " << senior.getGrade() << std::endl;

		std::cout << "Trying to increment by 1..." << std::endl;
		senior.incrementGrade();
		std::cout << "After increment: " << senior << std::endl;
	
		std::cout << "Trying to decrement by 1..." << std::endl;
		senior.decrementGrade();
		std::cout << "After decrement: " << senior << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat president("President", 1);
		std::cout << "Initial " << president.getName() << "'s grade is: " << president.getGrade() << std::endl;
		president.incrementGrade();
		std::cout << "After increment: " << president << "\n" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat newbie("Newbie", 150);
		std::cout << "Initial " << newbie.getName() << "'s grade is: " << newbie.getGrade() << std::endl;
		newbie.decrementGrade();
		std::cout << "After decrement: " << newbie << "\n" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n---\n" << std::endl;

	std::cout << "- Cleaning: - \n" << std::endl;

    return (0);
}
