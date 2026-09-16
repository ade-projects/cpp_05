/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:30:06 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/16 18:43:43 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "\n - Constructors and overload testing: - \n" << std::endl;

	Bureaucrat defaultBureaucrat;
	std::cout << "Instance's attributes: " << defaultBureaucrat << "\n" << std::endl;	

	Bureaucrat tidus("Tidus", 42);
	std::cout << "Instance's attributes: " << tidus << "\n" << std::endl;
	
	Bureaucrat tidusClone(tidus);
	std::cout << "Instance's attributes: " << tidusClone << "\n" << std::endl;

	defaultBureaucrat = tidus;
	std::cout << "Instance's attributes: " << defaultBureaucrat << std::endl;
	std::cout << "(as _name is constant only _grade can be copied)" << std::endl; 

	std::cout << "\n---\n" << std::endl;

	std::cout << " - Getter and increment/decrement testing: - \n" << std::endl;
	
	try
	{
		Bureaucrat yuna("Yuna", 23);
		std::cout << "Initial " << yuna.getName() << "'s grade is: " << yuna.getGrade() << "\n" << std::endl;
	
		yuna.incrementGrade();
		std::cout << "After increment: " << yuna << "\n" << std::endl;

		yuna.decrementGrade();
		std::cout << "After decrement: " << yuna << "\n" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}
	
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
		Bureaucrat highLevel("High Level", 0);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "Trying with grade 234:" << std::endl; 
		Bureaucrat lowLevel("Low Level", 234);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n---\n" << std::endl;

	std::cout << " - Exception testing: increment/decrement limits: - \n" << std::endl;

	try
	{
		Bureaucrat first("First one", 1);
		std::cout << first << std::endl;
		std::cout << "Trying to increment by 1..." << std::endl;
		first.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() <<  std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat last("Last one", 150);
		std::cout << last << std::endl;
		std::cout << "Trying to decrement by 1..." << std::endl;
		last.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n---\n" << std::endl;

	std::cout << "- Cleaning: - \n" << std::endl;

    return (0);
}
