/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:26:42 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/21 13:27:09 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	private:
		bool	guarding_gate;
	public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap( const ScavTrap& copy);
	ScavTrap& operator = (const ScavTrap& other);
	~ScavTrap();
	void attack(const std::string& target);
	void guardGate();
};

#endif
