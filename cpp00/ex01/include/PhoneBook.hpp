/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:28:16 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/06 15:57:36 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>

#ifndef MAX_CONTACT
#define MAX_CONTACT 8
#endif


class PhoneBook
{
	private:
		Contact	contactList[MAX_CONTACT];
		int		contactCount;

	public:
		void	addContact();
		void	searchContact();
		PhoneBook();
		~PhoneBook();
};

#endif
