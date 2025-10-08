/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 00:55:29 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/09 00:59:55 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon ) : name(name), weapon(weapon){};
HumanA::~HumanA() {};

void HumanA::attack( void )
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = weapon;
}
