/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:05:46 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/22 18:02:46 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

# define C_GRN   "\001\x1B[32m\002"
# define C_BLU   "\001\x1B[34m\002"
# define C_RED   "\001\x1B[31m\002"
# define C_RESET "\001\x1B[0m\002"

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();
		virtual void 	makeSound() const;
		std::string		getType( void ) const;
};

#endif
