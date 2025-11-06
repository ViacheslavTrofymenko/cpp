/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:44:15 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/06 10:37:22 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << C_GRN "After increment: " << a << C_RES <<std::endl;
        a.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << C_RED "Exception caught: " << e.what() << C_RES << std::endl;
    }

    try
    {
        Bureaucrat b("Bob", 150);
        std::cout << b << std::endl;
        b.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << C_RED "Exception caught: " << e.what() << C_RES << std::endl;
    }

    return 0;
}
