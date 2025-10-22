/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:53:19 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/22 19:38:23 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
	type = "Dog";
	std::cout << C_RED "Dog default constructor called" C_RESET <<std::endl;;
}

Dog::Dog (std::string type) : Animal(type), brain(new Brain())
{
	this->type = type;
	std::cout << C_RED "Dog constructor called" C_RESET <<std::endl;;
}

Dog::Dog(const Dog &other) : Animal(other), brain(NULL)
{
	if (other.brain)
        this->brain = new Brain(*other.brain);
    this->type = other.type;
    std::cout << C_RED "Dog copy constructor called" C_RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
        return *this;
    this->type = other.type;
    delete this->brain;
    if (other.brain)
        this->brain = new Brain(*other.brain);
    else
        this->brain = NULL;
    std::cout << C_RED "Dog copy assignment constructor called" C_RESET << std::endl;
    return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << C_RED "Dog destructor called" C_RESET <<std::endl;;
}

void Dog::makeSound() const
{
	std::cout << C_RED "Wau Wau Wau" C_RESET <<std::endl;
}

Brain*	Dog::getBrain() const
{
	return (this->brain);
}

void	Dog::setBrain(const Brain& new_brain)
{
	if (!this->brain)
		this->brain = new Brain();
	*(this->brain) = new_brain;
}
