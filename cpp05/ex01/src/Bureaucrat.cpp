/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:43:59 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/06 11:35:35 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(75)
{
	std::cout << C_GRN "Bureaucrat created with default constructor" C_RES << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, unsigned int grade) : _name(name)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	this->_grade = grade;
	std::cout << C_GRN "Bureaucrat " << _name << " created with grade " << _grade << C_RES << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade)
{
	std::cout << C_BLU "Bureaucrat copied" C_RES << std::endl;
}
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << C_RED "Bureaucrat " << _name << " destroyed" C_RES << std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= HIGHEST_GRADE)\
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= LOWEST_GRADE)
        throw GradeTooLowException();
    _grade++;
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat::GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat::GradeTooLowException";
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << C_BLU << b.getName() << ", bureaucrat grade " << b.getGrade() << C_RES << std::endl;
	return (out);
}

void Bureaucrat::signForm(Form &form)
{
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
