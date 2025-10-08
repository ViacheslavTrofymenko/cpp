/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:15:20 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/08 23:34:34 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << "🧟 " << this->name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}
Zombie::~Zombie()
{
	std::cout << "🧟 " << name << " destroyed!!!" << std::endl;
}
