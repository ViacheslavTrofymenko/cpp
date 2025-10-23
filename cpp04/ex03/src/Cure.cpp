/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:28:09 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/23 14:00:49 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"
#include "../include/Character.hpp"

Cure::Cure( ) : AMateria::AMateria( "cure" )
{
}
Cure::Cure( const Cure& copy ) : AMateria::AMateria( copy )
{
}
Cure::~Cure()
{
}
Cure& 	Cure::operator=( const Cure& copy )
{
	this->_type = copy.getType();
	return (*this);
}

Cure*	Cure::clone() const
{
	return new Cure();
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
