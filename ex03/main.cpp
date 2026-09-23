/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:18:29 by adeestev          #+#    #+#             */
/*   Updated: 2026/09/23 19:50:57 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <exception>
# include <cstdlib>   
# include <ctime>

int	main()
{
	srand(time(NULL));

	std::cout << "\n-- Intern tests: --\n" << std::endl;

	Intern newbieIntern;

	AForm* shrubForm;
	AForm* robotForm;
	AForm* presidentForm;
	AForm* unknownForm;

	shrubForm = newbieIntern.makeForm("shrubbery_creation", "Garden");
	robotForm = newbieIntern.makeForm("robotomy_request", "Hal");
	presidentForm = newbieIntern.makeForm("presidential_pardon", "TheBoss");
	unknownForm = newbieIntern.makeForm("unknow_form", "NoOne");

	std::cout << std::endl;

	std::cout << "-- Cleaning: --\n" << std::endl;

	delete shrubForm;
	delete robotForm;
	delete presidentForm;
	delete unknownForm;

	return (0);
}
