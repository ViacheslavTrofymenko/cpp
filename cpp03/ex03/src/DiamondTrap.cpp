/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:10:01 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/21 13:54:55 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name")
{
	this->name = "default";
	this->hit_pts = FragTrap::hit_pts;
	this->energy_pts = ScavTrap::energy_pts;
	this->attack_dmg = FragTrap::attack_dmg;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	this->name = name;
	this->hit_pts = FragTrap::hit_pts;
	this->energy_pts = ScavTrap::energy_pts;
	this->attack_dmg = FragTrap::attack_dmg;
	std::cout << "DiamondTrap Constructor for the name " << this->name << " called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->name = src.name + "_clap_name";
	this->hit_pts = src.hit_pts;
	this->energy_pts = src.energy_pts;
	this->attack_dmg = src.attack_dmg;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "I'm a DiamondTrap and my name is " << this->name;
	std::cout << ", ClapTrap name is " << this->ClapTrap::name << std::endl;
}

