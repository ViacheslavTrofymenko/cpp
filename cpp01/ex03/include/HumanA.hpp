/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 00:34:44 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/09 00:48:56 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon&		weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void attack(void);
		void setWeapon(Weapon &weapon);
};

#endif
