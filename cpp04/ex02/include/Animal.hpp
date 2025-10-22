/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:05:46 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/22 21:56:44 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

# define C_GRN   "\001\x1B[32m\002"
# define C_BLU   "\001\x1B[34m\002"
# define C_RED   "\001\x1B[31m\002"
# define C_RESET "\001\x1B[0m\002"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& copy);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		virtual void 	makeSound() const = 0;
		std::string		getType( void ) const;
};

#endif
