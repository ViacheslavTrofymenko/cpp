/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:30:57 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/22 17:51:18 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << C_BLU "Cat default constructor called" C_RESET <<std::endl;;
}

Cat::Cat (std::string type) : Animal(type)
{
	this->type = type;
	std::cout << C_BLU "Cat constructor called" C_RESET <<std::endl;;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
	std::cout << C_BLU "Cat copy constructor called" C_RESET <<std::endl;;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.type;
	std::cout << C_BLU "Cat copy assignment constructor called" C_RESET <<std::endl;;
	return (*this);
}

Cat::~Cat()
{
	std::cout << C_BLU "Cat destructor called" C_RESET <<std::endl;;
}

void Cat::makeSound() const
{
	std::cout << C_BLU "Miau Miau Miau" C_RESET <<std::endl;
}
