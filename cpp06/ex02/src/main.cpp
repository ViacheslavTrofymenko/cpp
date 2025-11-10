/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:25:55 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/10 10:26:16 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../include/functions.hpp"

int main()
{
	std::srand(std::time(NULL));

	Base *obj = generate();

	std::cout << "identify(Base*): ";
	identify(obj);

	std::cout << "identify(Base&): ";
	identify(*obj);

	delete obj;
	return 0;
}
