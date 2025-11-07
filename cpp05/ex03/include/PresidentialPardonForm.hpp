/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:50:21 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/07 10:18:50 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
	private:
	std::string _target;

	protected:
	virtual void executeAction() const;

	public:
	PresidentialPardonForm(std::string const &target);
	virtual ~PresidentialPardonForm();
};
