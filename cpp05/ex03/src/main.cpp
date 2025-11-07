/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:44:15 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/07 13:26:23 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm *form;

	form = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	if (form)
	{
		Bureaucrat boss("Bob", 1);
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	form = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
	if (form)
	{
		Bureaucrat boss("Bob", 1);
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	form = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
	if (form)
	{
		Bureaucrat boss("Bob", 75);
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << std::endl;
	form = someRandomIntern.makeForm("unknown form", "Nobody");
	if (form)
		delete form;
	return (0);
}
