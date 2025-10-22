/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:53:19 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/22 17:55:23 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << C_RED "Dog default constructor called" C_RESET <<std::endl;;
}

Dog::Dog (std::string type) : Animal(type)
{
	this->type = type;
	std::cout << C_RED "Dog constructor called" C_RESET <<std::endl;;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	*this = other;
	std::cout << C_RED "Dog copy constructor called" C_RESET <<std::endl;;
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.type;
	std::cout << C_RED "Dog copy assignment constructor called" C_RESET <<std::endl;;
	return (*this);
}

Dog::~Dog()
{
	std::cout << C_RED "Dog destructor called" C_RESET <<std::endl;;
}

void Dog::makeSound() const
{
	std::cout << C_RED "Wau Wau Wau" C_RESET <<std::endl;
}
