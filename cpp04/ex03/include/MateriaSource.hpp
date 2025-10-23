/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:22:57 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/23 13:27:35 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_SOURCE_HPP
#define MATERIAL_SOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

class	MateriaSource : virtual public IMateriaSource
{
	private:
	AMateria*	_inventory[MAX_MATERIA];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource& operator=(const MateriaSource &src);
		~MateriaSource();

		void	learnMateria(AMateria *materia);
		AMateria* createMateria(const std::string &type);
		const AMateria*	getMateria( int index ) const;
};

#endif
