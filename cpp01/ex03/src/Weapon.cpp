/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 00:51:06 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/09 00:54:53 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std:: string type)
{
	this->type = type;
}
Weapon::Weapon() {}

Weapon::~Weapon() {}

void Weapon::setType(std::string type)
{
	this->type = type;
}
const std::string& Weapon::getType(void) const
{
	return (type);
}
