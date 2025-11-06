/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:47:59 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/06 21:49:24 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
	std::string _target;

	public:
	ShrubberyCreationForm(std::string const &target);
	virtual ~ShrubberyCreationForm();
	protected:
	virtual void executeAction() const;
};
