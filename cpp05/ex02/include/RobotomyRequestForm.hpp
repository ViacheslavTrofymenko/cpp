/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:49:33 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/07 10:19:33 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
	std::string _target;

	protected:
	virtual void executeAction() const;

	public:
	RobotomyRequestForm(std::string const &target);
	virtual ~RobotomyRequestForm();
};
