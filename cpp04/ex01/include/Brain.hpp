/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:43:04 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/22 18:56:15 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#define QTY_IDEAS 100

#include <iostream>

class Brain
{
	protected:
		std::string	ideas[QTY_IDEAS];
	public:
		Brain( );
		Brain(const Brain& copy );
		~Brain();
		Brain&		operator=(const Brain& copy);
		std::string	getIdea( int index ) const;
		void		setIdea( const std::string& idea, int index);
};

#endif
