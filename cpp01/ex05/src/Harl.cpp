/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:22:08 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/09 14:33:47 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup "
	"burger. I really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
	"You didn't put enough bacon in my burger!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. "
	"I've been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level)
{
	void		(Harl::*funcs[NUMS])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	func_names[NUMS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < NUMS; i++)
	{
		if (func_names[i] == level)
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cerr << level << ": Function not found" << std::endl;
}
