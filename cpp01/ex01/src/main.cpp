/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:15:23 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/09 00:00:01 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie_ptr;
	int		nums = 5;

	zombie_ptr = zombieHorde(nums, "Bob");
	for (int i = 0; i < nums; i++)
		zombie_ptr[i].announce();
	delete[] zombie_ptr;
	return (0);
}
