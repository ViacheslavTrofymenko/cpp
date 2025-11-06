/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:15:48 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/06 21:53:35 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const unsigned int	gradeToSign;
		const unsigned int	gradeToExecute;

	protected:
		virtual void executeAction() const = 0;

	public:
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
		virtual ~AForm();

		const std::string &getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat const &bureaucrat);
		void execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
   		};

		class NotSignedException : public std::exception {
		virtual const char* what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, AForm const &f);
