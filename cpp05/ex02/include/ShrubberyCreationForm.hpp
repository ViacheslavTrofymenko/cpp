/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:47:59 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/07 10:19:47 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
	std::string _target;

	protected:
	virtual void executeAction() const;

	public:
	ShrubberyCreationForm(std::string const &target);
	virtual ~ShrubberyCreationForm();
};
