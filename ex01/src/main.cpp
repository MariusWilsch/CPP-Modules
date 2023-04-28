/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:00:16 by verdant           #+#    #+#             */
/*   Updated: 2023/04/28 16:40:31 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main(void)
{
	int n_zombies = 3;
	Zombie *zombies = zombieHorde(n_zombies, "Zombie");
	for (int i = 0; i < n_zombies; i++)
		zombies[i].announce();

	delete [] zombies;
}