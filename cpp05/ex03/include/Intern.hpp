/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:15:03 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/07 13:18:57 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	private:
		AForm*	createShrubberyCreationForm(const std::string &target ) const;
		AForm*	createRobotomyRequestForm(const std::string &target ) const;
		AForm*	createPresidentialPardonForm(const std::string &target ) const;

	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm *makeForm(std::string const &formName, std::string const &target);
};
