/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:28:10 by verdant           #+#    #+#             */
/*   Updated: 2023/05/13 16:01:48 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "animal.hpp"
# include "animalBrain.hpp"

// The virtual keywords tells the code that it should check if the
// derived class has its own implementation of the function.
int main(void)
{
	Animal* animals[100];
	for (int i = 0; i < 100; i++)
	{
		if (i < 50)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 100; i++)
		delete animals[i];
	// system("leaks -q brain");
}