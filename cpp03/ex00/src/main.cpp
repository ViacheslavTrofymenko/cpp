/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:10:55 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/16 18:58:52 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main( void ) {
	ClapTrap a;
	ClapTrap b("Bob");
	ClapTrap c("Alice");

	a.setAttackDamage(3);
	b.setAttackDamage(4);
	c.setAttackDamage(5);

	for (int i = 0; i <= 4; i++)
	{
		a.attack("Bob");
		b.takeDamage(a.getAttackDamage());
	}

	b.beRepaired(8);

	for (int i = 0; i <= 10; i++)
	{
		c.attack("dummy");
	}
	c.attack("dummy2");


	return ( 0 );
}
