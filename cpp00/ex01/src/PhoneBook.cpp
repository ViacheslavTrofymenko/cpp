/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:29:56 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/07 11:43:23 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string formatStr(std::string str)
{
	if (str.length() < 10)
	{
		return (str);
	}
	else
	{
		str = str.substr(0, 10);
		str[9] = '.';
	}
	return (str);
}

bool isValidPhoneNumber(std::string &phone)
{
	if (phone.empty())
		return false;

	size_t start = 0;

	if (phone[0] == '+')
		start = 1;
	for (size_t i = start; i < phone.size(); ++i)
	{
		if (!isdigit(phone[i]))
			return (false);
	}
	return (true);
}

void PhoneBook::addContact()
{
	Contact contact;
	std::string input;
	static int index = 0;

	std::cout << "Enter first name: " << std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Field can not be empty. Please try again." << std::endl;
		std::cout << "Enter first name: " << std::endl;
		std::getline(std::cin, input);
	}
	contact.setName(input);
	std::cout << "Enter last name: " << std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Field can not be empty. Please try again." << std::endl;
		std::cout << "Enter last name: " << std::endl;
		std::getline(std::cin, input);
	}
	contact.setLastName(input);
	std::cout << "Enter nickName" << std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Field can not be empty. Please try again." << std::endl;
		std::cout << "Enter nickName" << std::endl;
		std::getline(std::cin, input);
	}
	contact.setNickname(input);
	std::cout << "Enter phoneNumber" << std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Field can not be empty. Please try again." << std::endl;
		std::cout << "Enter phoneNumber" << std::endl;
		std::getline(std::cin, input);
	}
	while (!isValidPhoneNumber(input))
	{
		std::cout << "Invalid phone number. Only digits allowed and optional + at the start." << std::endl;
		std::cout << "Try again: ";
		std::getline(std::cin, input);
	}
	contact.setPhoneNumber(input);
	std::cout << "Store your darkest secret:" << std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Field can not be empty. Please try again." << std::endl;
		std::cout << "Store your darkest secret:" << std::endl;
		std::getline(std::cin, input);
	}
	contact.setSecret(input);
	contact.setIndex(index);
	contactList[index] = contact;
	if (index == MAX_CONTACT - 1)
		index = 0;
	else
		index++;
	if (contactCount < MAX_CONTACT - 1)
		contactCount++;
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact()
{
	unsigned int index;

	if (contactCount == -1)
	{
		std::cerr << "There is no contacts in phoneBook" << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::string(43, '-') << std::endl;
	for (int i = 0; i <= contactCount; ++i)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << formatStr(contactList[i].getName()) << "|"
				  << std::setw(10) << formatStr(contactList[i].getLastName()) << "|"
				  << std::setw(10) << formatStr(contactList[i].getNickname()) << std::endl;
	}
	std::cout << "\nEnter the index of the contact to view details: ";
	std::cin >> index;
	if (std::cin.fail() || index > (unsigned int)contactCount)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index. Please try SEARCH again." << std::endl;
		return;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "\n=== Contact information: ===\n";
	std::cout << "First name:  " << contactList[index].getName() << std::endl;
	std::cout << "Last name:   " << contactList[index].getLastName() << std::endl;
	std::cout << "Nickname:    " << contactList[index].getNickname() << std::endl;
	std::cout << "Phone:       " << contactList[index].getPhoneNumber() << std::endl;
	std::cout << "Secret:      " << contactList[index].getSecret() << std::endl;
}

PhoneBook::PhoneBook()
{
	contactCount = -1;
}

PhoneBook::~PhoneBook()
{
}
