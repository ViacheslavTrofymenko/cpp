/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:21:43 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/21 13:01:18 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->hit_pts = 100;
	this->energy_pts = 100;
	this->attack_dmg = 30;
	std::cout << C_GRN "FragTrap Default constructor called." C_RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_pts = 100;
	this->energy_pts = 100;
	this->attack_dmg = 30;
	std::cout << C_GRN "FragTrap Constructor for the " << name << " called" C_RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << C_GRN "FragTrap Assignation operator called" C_RESET << std::endl;
	this->name = src.name;
	this->hit_pts = src.hit_pts;
	this->energy_pts = src.energy_pts;
	this->attack_dmg = src.attack_dmg;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << C_RED"FragTrap Destructor for the " << name << " called." C_RESET << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << ": Hey, bro give me five." << std::endl;
}
