/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:28:06 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/23 14:00:48 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"
#include "../include/Character.hpp"

Ice::Ice() : AMateria::AMateria("ice")
{
}
Ice::Ice(const Ice &copy) : AMateria::AMateria(copy)
{
}
Ice::~Ice()
{
}
Ice& Ice::operator=(const Ice &copy)
{
	this->_type = copy.getType();
	return (*this);
}

Ice *Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
