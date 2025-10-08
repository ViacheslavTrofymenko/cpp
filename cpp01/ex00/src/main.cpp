/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:15:23 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/08 23:40:05 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z;

	randomChump("Walking dead");
	z = newZombie("Dead gibbon");
	z->announce();
	delete z;
	return (0);
}
