/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:28:11 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/23 14:00:53 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

Character::Character(void) : _name("default")
{
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
	std::cout << "Character created with default constructor" << std::endl;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
	std::cout << "Character created" << std::endl;
}

Character::Character(Character const &copy) : ICharacter(copy)
{
	this->_name = copy._name;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << "Character copied" << std::endl;
}

Character &Character::operator=(const Character &copy)
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
	this->_name = copy.getName();
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
}

const std::string &Character::getName(void) const
{
	return this->_name;
}

AMateria *Character::getMateria(int index) const
{
	if (index < 0 || index >= MAX_MATERIA)
		return NULL;
	return this->_inventory[index];
}

void Character::equip(AMateria *materia)
{
	if (materia == NULL)
		return;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			std::cout << this->_name << " equips " << materia->getType() << std::endl;
			return;
		}
	}
	std::cout << this->_name << "'s inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_MATERIA)
    {
        std::cout << "Invalid unequip index: " << idx << std::endl;
        return;
    }
    if (this->_inventory[idx] == NULL)
    {
        std::cout << this->_name << " has nothing to unequip in slot " << idx << std::endl;
        return;
    }
    this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= MAX_MATERIA)
	{
		std::cout << "Invalid slot index: " << idx << std::endl;
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << " has no materia in slot " << idx << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}
