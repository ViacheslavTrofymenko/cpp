/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:50:21 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/06 21:50:51 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
	private:
	std::string _target;


	public:
	PresidentialPardonForm(std::string const &target);
	virtual ~PresidentialPardonForm();


	protected:
	virtual void executeAction() const;
	};
