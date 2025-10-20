/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:10:55 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/20 14:05:08 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int main( void ) {
	{
		ClapTrap a;
		ClapTrap b("Alice");

		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Cody-clone");
		b.beRepaired(3);
	}
	std::cout << "===================================================" << std::endl;
	{
		ScavTrap c;
		ScavTrap d("Bob");

		c.attack("some other robot");
		c.takeDamage(10);
		c.takeDamage(10);
		c.beRepaired(5);
		c.attack("some other other robot");
		d.beRepaired(3);
		for (int i = 0; i < 12; i++)
			d.attack("Cody-clone");
		d.beRepaired(3);
	}


	return ( 0 );
}
