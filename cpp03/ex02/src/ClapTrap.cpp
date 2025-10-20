/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:10:57 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/16 19:00:50 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hit_pts(10), energy_pts(10), attack_dmg(0)
{
	std::cout << C_GRN "ClapTrap Default Constructor called." C_RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_pts(10), energy_pts(10), attack_dmg(0)
{
	std::cout << C_GRN "ClapTrap Constructor for the " << name << " called." C_RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << C_GRN "Claptrap Copy Constructor called." C_RESET << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << C_RED"ClapTrap Destructor for the " << name << " called." C_RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << C_GRN "ClapTrap Assignation operator called" C_RESET << std::endl;
	this->name = src.name;
	this->hit_pts = src.hit_pts;
	this->energy_pts = src.energy_pts;
	this->attack_dmg = src.attack_dmg;
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->energy_pts > 0 && this->hit_pts > 0)
	{
		std::cout << C_BLU "ClapTrap " << name << " attacks " << target <<
		", causing " << attack_dmg << " points of damage." C_RESET << std::endl;
		this->energy_pts--;
	}
	else if (this->energy_pts == 0)
	{
		std::cout << C_RED "ClapTrap " << this->name << " is not able to attack " <<
		target << ", because he has no energy points left." C_RESET << std::endl;
	}
	else
	{
		std::cout << C_RED "ClapTrap " << this->name << " is not able to attack " <<
		target << ", because he has not enough hit points." C_RESET << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_pts > amount)
		this->hit_pts -= amount;
	else if (this->hit_pts > 0)
		this->hit_pts = 0;
	else
	{
		std::cout << C_BLU "ClapTrap " << this->name << " is already dead, stop beating it." C_RESET << std::endl;
		return ;
	}
	std::cout << C_BLU "ClapTrap " << this->name << " was attacked and lost " <<
	amount << " hit points, he now has " << this->hit_pts << " hit points." C_RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_pts > 0 && this->hit_pts > 0 && this->hit_pts + amount <= 10)
	{
		this->hit_pts += amount;
		std::cout << C_BLU "ClapTrap " << this->name << " repaired itself and gained " <<
		amount << " of hit points, he now has " << this->hit_pts << "hit points." C_RESET << std::endl;
		this->energy_pts--;
	}
	else if (this->energy_pts == 0)
		std::cout << C_RED "ClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough energy points." C_RESET << std::endl;
	else if (this->hit_pts == 0)
		std::cout << C_RED "ClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough hit points." C_RESET << std::endl;
	else
	std::cout << C_RED "ClapTrap " << this->name << " can't be repaired to have more than 10 hit points." C_RESET << std::endl;
}

void ClapTrap::setAttackDamage( unsigned int new_dmg)
{
	if (new_dmg > 5)
	{
		std::cout << "Attack damage can not be more than 5" << std::endl;
		return ;
	}
	std::cout << C_BLU "New attack damage for " << name << " is " << new_dmg << C_RESET << std::endl;
	this->attack_dmg = new_dmg;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return (this->attack_dmg);
}

