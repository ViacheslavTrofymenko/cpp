/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:28:56 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/06 18:09:17 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	print_instructions()
{
	std::cout << "Run one of the following commands: ADD, SEARCH or EXIT" << std::endl;
	std::cout << "ADD for adding contact, SEARCH for looking up a contact and EXIT";
	std::cout << " program quits and the contacts are lost forever!" << std::endl;
}

int	main()
{
	std::string	input;
	PhoneBook	phone_book;

	print_instructions();
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
			phone_book.addContact();
		else if (input == "SEARCH")
			phone_book.searchContact();
		else if (input == "EXIT")
			return (0);
		else if (!input.empty())
			std::cout << "Incorrect input" << std::endl;
	}
	return (1);
}
