/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:48:44 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/22 18:57:47 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"
#include "../include/Animal.hpp"

Brain::Brain(void)
{
	std::cout << C_GRN "🧠 Brain default constructor called." C_RESET << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << C_GRN "🧠 Brain copy constructor called." C_RESET << std::endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain &b)
{
	for (int i = 0; i < QTY_IDEAS; i++)
		this->ideas[i] = b.ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << C_GRN "🧠 Brain default destructor called." C_RESET << std::endl;
}

void Brain::setIdea( const std::string& idea, int index)
{
	if (index >= 0 && index < QTY_IDEAS)
		this->ideas[index] = idea;
	else
		std::cout << C_RED "Not valid index to set idea." C_RESET << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < QTY_IDEAS)
		return (this->ideas[index]);
	else
		std::cout << C_RED "Not valid index to set idea." C_RESET << std::endl;
	return ("");
}
