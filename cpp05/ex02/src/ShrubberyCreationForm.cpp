/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:48:40 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/06 21:49:00 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
: AForm("ShrubberyCreationForm",145,137), _target(target) {}


ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::executeAction() const {
std::ofstream file((_target + "_shrubbery").c_str());
file << " ccee88oo\n C8O8O8Q8PoOb o8oo\n dOB69QO8PuOpugoO9bD\n";
}
