/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:56:03 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/10/22 19:22:41 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Brain.hpp"
#include "../include/Dog.hpp"

int main()
{
	Animal*	animals[4];

	Dog		dog1;
	Brain	brainAI;

	for(int i = 0; i < QTY_IDEAS; i++)
		brainAI.setIdea("Cats are friends", i);
	dog1.setBrain(brainAI);

	Dog	dog_copy(dog1);

	dog_copy.getBrain()->setIdea("Sleep", 0);
	std::cout << "\nOriginal thought: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy thought: " << dog_copy.getBrain()->getIdea(0) << std::endl;
	std::cout << "\nARRAY CREATION\n\n";

	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}
	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}
