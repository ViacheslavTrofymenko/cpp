/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:44:15 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/07 12:10:36 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat high("Alice", 1);
		Bureaucrat low("Bob", 150);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Marvin");

		std::cout << "---- Signing Forms ----" << std::endl;
		high.signForm(shrub);
		high.signForm(robot);
		high.signForm(pardon);

		std::cout << "\n---- Executing Forms ----" << std::endl;
		high.executeForm(shrub);
		high.executeForm(robot);
		high.executeForm(pardon);

		std::cout << "\n---- Trying with low grade ----" << std::endl;
		low.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
