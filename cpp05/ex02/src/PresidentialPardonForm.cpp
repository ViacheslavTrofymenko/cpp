/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:50:32 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/06 21:51:01 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
: AForm("PresidentialPardonForm",25,5), _target(target) {}


PresidentialPardonForm::~PresidentialPardonForm() {}


void PresidentialPardonForm::executeAction() const {
std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
