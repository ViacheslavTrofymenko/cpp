/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:29:41 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/06 10:17:48 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

# define C_GRN	"\001\x1B[32m\002"
# define C_BLU	"\001\x1B[34m\002"
# define C_RED	"\001\x1B[31m\002"
# define C_RES	"\001\x1B[0m\002"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, unsigned int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string  &getName() const;
		unsigned int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
