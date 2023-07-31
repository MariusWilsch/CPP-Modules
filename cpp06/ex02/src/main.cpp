/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:31:19 by verdant           #+#    #+#             */
/*   Updated: 2023/07/31 12:47:21 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"

int main(void)
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}