/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:10:20 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/09 22:18:58 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Serializer.hpp"
#include "../include/Data.hpp"

int main()
{
	Data data;
	data.number = 42;
	data.text = "Hello Madrid!";

	std::cout << "Original Data:" << std::endl;
	std::cout << "  number = " << data.number << std::endl;
	std::cout << "  text   = " << data.text << std::endl;

	uintptr_t raw = Serializer::serialize(&data);

	Data *ptr = Serializer::deserialize(raw);

	std::cout << "\nAfter deserialization:" << std::endl;
	std::cout << "  number = " << ptr->number << std::endl;
	std::cout << "  text   = " << ptr->text << std::endl;
	if (ptr == &data)
		std::cout << "\n SUCCESS: Pointer restored correctly!" << std::endl;
	else
		std::cout << "\n ERROR: Pointer mismatch!" << std::endl;
	return 0;
}
