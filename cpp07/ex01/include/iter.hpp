/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:06:11 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/12 19:06:56 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

template <typename T, typename F>
void iter(T *array, const std::size_t length, F func)
{
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}
