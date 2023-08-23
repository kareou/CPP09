/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:21:50 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/23 12:53:01 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cerr << "error\n";
		exit(1);
	}
	RPN rpn;
	std::string input = av[1];
	rpn.readInput(input);
	rpn.calculate();
}
