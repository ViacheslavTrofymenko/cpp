/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:28:08 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/07 11:44:43 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact
{
	private:
		std::string			secret;
		std::string			name;
		std::string			last_name;
		std::string			nickname;
		std::string			phone_number;
		int					index;
	public:
		void				setName(std::string& name);
		void				setLastName(std::string& lastName);
		void				setNickname(std::string& nickName);
		void				setPhoneNumber(std::string& phoneNumber);
		void				setSecret(std::string& secret);
		void				setIndex(int i);
		const std::string	&getSecret(void) const;
		const std::string	&getName(void) const;
		const std::string	&getLastName(void) const;
		const std::string	&getNickname(void) const;
		const std::string	&getPhoneNumber(void) const;
		int					getIndex(void) const;
		Contact();
	~Contact();
};

#endif
