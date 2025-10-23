/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:23:42 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/23 14:00:42 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_inventory[i] = NULL;
}
MateriaSource::MateriaSource( const MateriaSource& copy )
{
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_inventory[i] = NULL;
	*this = copy;
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
}
const AMateria*	MateriaSource::getMateria( int index) const
{
	return this->_inventory[index];
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& copy )
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (copy.getMateria(i) != NULL)
			this->_inventory[i] = copy.getMateria(i)->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria( AMateria* materia )
{
	int	index = 0;

	while (this->_inventory[index] != NULL && index < MAX_MATERIA)
		index++;
	if (index < MAX_MATERIA)
	{
		this->_inventory[index] = materia;
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	AMateria	*find = NULL;

	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_inventory[i] != NULL && this->_inventory[i]->getType() == type)
			find = this->_inventory[i]->clone();
	}
	return find;
}
