/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 23:44:52 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/08 23:57:52 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*ptr;

	ptr = new Zombie[N];
	for (int i = 0; i < N; i++)
		ptr[i].setName(name);
	return (ptr);
}
