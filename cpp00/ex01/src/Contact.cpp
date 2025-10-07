/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:43:53 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/06 18:04:06 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

void	Contact::setName(std::string& name)
{
	this->name = name;
}

void	Contact::setLastName(std::string& lastName)
{
	this->last_name = lastName;
}

void	Contact::setNickname(std::string& nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(std::string& phoneNumber)
{
	this->phone_number = phoneNumber;
}

void Contact::setSecret(std::string& secret)
{
	this->secret = secret;
}

void Contact::setIndex(int i)
{
	this->index = i;
}

const std::string& Contact::getSecret(void) const
{
	return (secret);
}

const std::string& Contact::getName(void) const
{
	return (name);
}

const std::string& Contact::getLastName(void) const
{
	return (last_name);
}

const std::string& Contact::getNickname(void) const
{
	return (nickname);
}

const std::string& Contact::getPhoneNumber(void) const{
	return(phone_number);
}

int Contact::getIndex(void) const
{
	return (index);
}

Contact::Contact()
{
	index = 0;
}

Contact::~Contact()
{

}
