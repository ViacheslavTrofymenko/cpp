/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:30:57 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/22 19:38:18 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
	type = "Cat";
	std::cout << C_BLU "Cat default constructor called" C_RESET <<std::endl;;
}

Cat::Cat (std::string type) : Animal(type), brain(new Brain())
{
	this->type = type;
	std::cout << C_BLU "Cat constructor called" C_RESET <<std::endl;;
}

Cat::Cat(const Cat &other) : Animal(other), brain(NULL)
{
    if (other.brain)
        this->brain = new Brain(*other.brain);
    this->type = other.type;
    std::cout << C_BLU "Cat copy constructor called" C_RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this == &other)
        return *this;

    this->type = other.type;

    delete this->brain;

    if (other.brain)
        this->brain = new Brain(*other.brain);
    else
        this->brain = NULL;
    std::cout << C_BLU "Cat copy assignment constructor called" C_RESET << std::endl;
    return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << C_BLU "Cat destructor called" C_RESET <<std::endl;;
}

void Cat::makeSound() const
{
	std::cout << C_BLU "Miau Miau Miau" C_RESET <<std::endl;
}

Brain*	Cat::getBrain() const
{
	return (this->brain);
}

void	Cat::setBrain(const Brain& new_brain)
{
	if (!this->brain)
		this->brain = new Brain();
	*(this->brain) = new_brain;
}
