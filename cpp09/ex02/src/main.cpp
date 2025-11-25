/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:50:00 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/25 21:34:54 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Error: Missing arguments. Usage: ./PmergeMe <sequence of positive integers>" << std::endl;
        return 1;
    }
    try {
        PmergeMe sorter;
        sorter.process(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }
    return 0;
}
