/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:30:57 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/22 17:51:18 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << C_BLU "WrongCat default constructor called" C_RESET <<std::endl;;
}

WrongCat::WrongCat (std::string type) : WrongAnimal(type)
{
	this->type = type;
	std::cout << C_BLU "WrongCat constructor called" C_RESET <<std::endl;;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	*this = other;
	std::cout << C_BLU "WrongCat copy constructor called" C_RESET <<std::endl;;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	this->type = other.type;
	std::cout << C_BLU "WrongCat copy assignment constructor called" C_RESET <<std::endl;;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << C_BLU "WrongCat destructor called" C_RESET <<std::endl;;
}

void WrongCat::makeSound() const
{
	std::cout << C_BLU "Oionk Oink Oink" C_RESET <<std::endl;
}
