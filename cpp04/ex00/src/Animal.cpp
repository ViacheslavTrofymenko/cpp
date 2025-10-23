/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:22:20 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/23 14:54:20 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() : type("Default")
{
	std::cout << C_GRN "Animal default constructor called" C_RESET <<std::endl;
}

Animal::Animal (std::string type) : type(type)
{
	std::cout << C_GRN "Animal constructor called" C_RESET <<std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << C_GRN "Animal copy constructor called" C_RESET <<std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this == &other)
          return *this;
      type = other.type;
      std::cout << C_GRN "Animal copy assignment constructor called" C_RESET <<std::endl;
      return (*this);
}

Animal::~Animal()
{
	std::cout << C_GRN "Animal destructor called" C_RESET <<std::endl;
}

void Animal::makeSound() const
{
	std::cout << C_GRN "Animal could make several different sounds" C_RESET <<std::endl;
}

std::string		Animal::getType( void ) const
{
	return (type);
}

