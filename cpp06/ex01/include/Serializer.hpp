/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:30:27 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/09 22:20:07 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

class Data;

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
		~Serializer();
};
