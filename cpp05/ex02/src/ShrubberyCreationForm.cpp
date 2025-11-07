/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:48:40 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/07 12:07:22 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile)
	{
		std::cerr << "Error: Could not open file\n";
		return;
	}

	outfile << "       _-_\n";
	outfile << "    /~~   ~~\\\n";
	outfile << " /~~         ~~\\\n";
	outfile << "{               }\n";
	outfile << " \\  _-     -_  /\n";
	outfile << "   ~  \\\\ //  ~\n";
	outfile << "_- -   | | _- _\n";
	outfile << "  _ -  | |   -_\n";
	outfile << "      // \\\\\n";

	outfile.close();
}
