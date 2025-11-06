/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:44:15 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/06 11:36:54 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("Alex", 50);
    Form f("Tax Form", 40, 20);

    a.signForm(f);

    Bureaucrat b("Bob", 10);
    b.signForm(f);

    std::cout << f << std::endl;

    return 0;
}
