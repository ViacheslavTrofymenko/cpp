/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:22:20 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/22 18:07:02 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default")
{
	std::cout << C_GRN "WrongAnimal default constructor called" C_RESET <<std::endl;
}

WrongAnimal::WrongAnimal (std::string type) : type(type)
{
	std::cout << C_GRN "WrongAnimal constructor called" C_RESET <<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << C_GRN "WrongAnimal copy constructor called" C_RESET <<std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	type = other.type;
	std::cout << C_GRN "WrongAnimal copy assignment constructor called" C_RESET <<std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << C_GRN "WrongAnimal destructor called" C_RESET <<std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << C_GRN "WrongAnimal could make several different sounds" C_RESET <<std::endl;
}

std::string		WrongAnimal::getType( void ) const
{
	return (type);
}

