/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:21:43 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/20 13:59:17 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->hit_pts = 100;
	this->energy_pts = 50;
	this->attack_dmg = 20;
	this->guarding_gate = false;
	std::cout << C_GRN "ScavTrap Default constructor called." C_RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_pts = 100;
	this->energy_pts = 50;
	this->attack_dmg = 20;
	this->guarding_gate = false;
	std::cout << C_GRN "ScavTrapConstructor for the " << name << " called" C_RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	this->guarding_gate = copy.guarding_gate;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << C_GRN "ScavTrap Assignation operator called" C_RESET << std::endl;
	this->name = src.name;
	this->hit_pts = src.hit_pts;
	this->energy_pts = src.energy_pts;
	this->attack_dmg = src.attack_dmg;
	this->guarding_gate = src.guarding_gate;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << C_RED"ScavTrap Destructor for the " << name << " called." C_RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energy_pts > 0 && this->hit_pts > 0)
	{
		std::cout << C_BLU "ScavTrap " << name << " attacks " << target <<
		", causing " << attack_dmg << " points of damage." C_RESET << std::endl;
		this->energy_pts--;
	}
	else if (this->energy_pts == 0)
	{
		std::cout << C_RED "ScavTrap " << this->name << " is not able to attack " <<
		target << ", because he has no energy points left." C_RESET << std::endl;
	}
	else
	{
		std::cout << C_RED "ScavTrap " << this->name << " is not able to attack " <<
		target << ", because he has not enough hit points." C_RESET << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (this->guarding_gate == false)
	{
		this->guarding_gate = true;
		std::cout << "ScavTrap " << this->name << " is now guarding the gate." << std::endl;
	}
	else
		std::cout << C_RED "ScavTrap " << this->name << " is already guarding the gate." C_RESET << std::endl;
}
