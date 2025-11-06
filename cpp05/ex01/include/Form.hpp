/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:15:48 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/06 11:39:47 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const unsigned int	gradeToSign;
		const unsigned int	gradeToExecute;
	public:
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(Form const &other);
		Form &operator=(Form const &other);
		~Form();

		const std::string &getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
   		};
};

std::ostream &operator<<(std::ostream &out, Form const &form);
