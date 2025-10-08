/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 00:34:46 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/09 00:50:53 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon*		weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void attack(void);
		void setWeapon(Weapon &weapon);
};

#endif
