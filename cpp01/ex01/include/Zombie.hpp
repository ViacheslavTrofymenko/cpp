/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:15:26 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/08 23:55:32 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		void	announce(void);
		void	setName(std::string name);
		Zombie();
		Zombie(std::string name);
		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif
