/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:44:15 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/06 21:53:44 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main() {
    std::srand(time(NULL));


    Bureaucrat boss("Boss", 1);
    ShrubberyCreationForm f1("home");
    RobotomyRequestForm f2("Bender");
    PresidentialPardonForm f3("Marvin");


    boss.signForm(f1);
    boss.executeForm(f1);


    boss.signForm(f2);
    boss.executeForm(f2);


    boss.signForm(f3);
    boss.executeForm(f3);


    return 0;
}
