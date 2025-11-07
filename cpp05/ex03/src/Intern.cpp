/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:48:40 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/07 13:22:40 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern()
{
	std::cout << C_GRN "Intern created with default constructor" C_RES << std::endl;
}

Intern::Intern(const Intern &) {}
Intern &Intern::operator=(const Intern &) { return *this; }
Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	const std::string formNames[3] = {
		"ShrubberyCreationForm",
		"PresidentialPardonForm",
		"RobotomyRequestForm"
	};

	AForm*	(Intern::*formCreators[3])(const std::string &) const = {
			&Intern::createShrubberyCreationForm,
			&Intern::createRobotomyRequestForm,
			&Intern::createPresidentialPardonForm
		};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*formCreators[i])(target));
		}
	}
	std::cerr << "Error: Form \"" << formName << "\" does not exist." << std::endl;
	return (NULL);
}
