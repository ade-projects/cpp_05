*This project has been created as part of the 42 curriculum by adeestev.*

## Description

C++ Module 05 introduces exceptions and nested class structures in C++98. The module is themed around a bureaucratic corporate nightmare, heavily utilizing try and catch blocks to manage execution flow and handle errors like out-of-bounds grades. It emphasizes the creation of custom exception classes nested within standard Orthodox Canonical Form classes.

## Exercises Overview

* **Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!**
Introduces the Bureaucrat class with a constant name and a grade ranging from 1 (highest) to 150 (lowest). Implements custom exceptions (GradeTooHighException and GradeTooLowException) that are thrown if a grade goes out of range during instantiation or when incrementing/decrementing.


* **Exercise 01: Form up, maggots!**
Adds a Form class featuring required grades to sign and execute. A Bureaucrat interacts with the Form via signForm() and beSigned() methods, verifying that the bureaucrat holds a sufficient grade to change the form's signature status.


* **Exercise 02: No, you need form 28B, not 28C...**
Refactors the base form into an abstract AForm class and implements three concrete derived forms: ShrubberyCreationForm (writes ASCII trees to a file), RobotomyRequestForm (50% success rate drill noise), and PresidentialPardonForm. Forms are executed polymorphically by a qualified Bureaucrat.


* **Exercise 03: At least this beats coffee-making**
Introduces an Intern class responsible for dynamically generating requested form objects via a makeForm() function. The implementation strictly forbids using messy if/elseif/else logic, requiring more elegant routing to return the correct AForm pointer.



## Instructions

Each exercise is isolated in its own directory (ex00 to ex03) and must be compiled independently.

* **Compiler:** c++

* **Compilation Flags:** -Wall -Wextra -Werror -std=c++98

* **Execution:** Run make inside the respective directory to build the executable, and run the generated binary to observe the exception handling outputs. Memory leaks are strictly forbidden.



## Resources

* **Documentation:** C++98 standard references for exception, try/catch blocks and abstract classes.
