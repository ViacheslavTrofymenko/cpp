/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:10:55 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/21 13:57:01 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int main( void ) {
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
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

	std::cout << "\n### TESTING SCAVTRAP ###\n" << std::endl;
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

	std::cout << "\n### TESTING FRAGTRAP ###\n" << std::endl;
	{
		FragTrap e;
		FragTrap f("Chadd");

		e.highFivesGuys();
		e.attack("some random dude");
		e.takeDamage(101);
		e.takeDamage(1);
		e.attack("some random dude");
		f.highFivesGuys();
	}

	std::cout << "\n### TESTING DIAMONDTRAP ###\n" << std::endl;
	{
		DiamondTrap a;
		DiamondTrap b("Daddy");
		DiamondTrap c(a);

		a.whoAmI();
		a.attack("some super random dude");
		b.whoAmI();
		b.attack("clone");
		c.whoAmI();
	}

	return ( 0 );
}
