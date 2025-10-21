/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:11:00 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/20 13:49:27 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP
#include <iostream>
#include <string>

# define C_GRN   "\001\x1B[32m\002"
# define C_BLU   "\001\x1B[34m\002"
# define C_RED   "\001\x1B[31m\002"
# define C_RESET "\001\x1B[0m\002"

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hit_pts;
		unsigned int	energy_pts;
		unsigned int	attack_dmg;
	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap( const ClapTrap& copy);
	ClapTrap& operator = (const ClapTrap& other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void setAttackDamage( unsigned int new_dmg);
	unsigned int getAttackDamage(void) const;

};

#endif
