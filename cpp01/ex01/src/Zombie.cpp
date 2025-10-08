/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:15:20 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/08 23:56:09 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << "🧟 " << this->name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::Zombie() {}

Zombie::Zombie(std::string name)
{
	this->name = name;
}
Zombie::~Zombie()
{
	std::cout << "🧟 " << name << " destroyed!!!" << std::endl;
}
