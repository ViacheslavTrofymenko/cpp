/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:49:33 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/06 21:49:43 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <cstdlib>


class RobotomyRequestForm : public AForm {
private:
std::string _target;


public:
RobotomyRequestForm(std::string const &target);
virtual ~RobotomyRequestForm();


protected:
virtual void executeAction() const;
};
