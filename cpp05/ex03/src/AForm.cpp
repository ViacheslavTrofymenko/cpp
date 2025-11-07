/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:22:31 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/07 10:20:49 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false),
	  gradeToSign(gradeToSign),
	  gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &other)
	: name(other.name),
	  isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign),
	  gradeToExecute(other.gradeToExecute)
{
}

AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm::GradeTooHighException");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm::GradeTooLowException");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("AForm: NotSignedException");
}

std::ostream &operator<<(std::ostream &out, AForm const &f)
{
	out << "AForm \"" << f.getName()
		<< "\" | signed: " << (f.getIsSigned() ? "yes" : "no")
		<< " | grade to sign: " << f.getGradeToSign()
		<< " | grade to execute: " << f.getGradeToExecute();
	return (out);
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned)
		throw NotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	this->executeAction();
}
