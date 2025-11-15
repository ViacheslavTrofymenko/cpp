/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:07:59 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/11/12 19:16:32 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/iter.hpp"

void increment(int &x) {
    ++x;
}

void printIntConst(const int &x) {
    std::cout << x << ' ';
}

template <typename T>
void printConstRef(const T &x) {
    std::cout << x << ' ';
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::size_t n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before increment: ";
    ::iter(arr, n, printIntConst);
    std::cout << '\n';
    ::iter(arr, n, increment);
    std::cout << "After increment: ";
    ::iter(arr, n, printIntConst);
    std::cout << "\n\n";

    const int carr[] = {10, 20, 30};
    std::size_t cn = sizeof(carr) / sizeof(carr[0]);

    std::cout << "Const array: ";
    ::iter(carr, cn, printConstRef<int>);
    std::cout << "\n";

    return (0);
}
