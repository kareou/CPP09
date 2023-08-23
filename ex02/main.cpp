/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:33:15 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/23 16:42:50 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac  == 1)
	{
		std::cerr << "Error: no ragument to be sorted\n";
		exit (1);
	}
	std::string input;
	for (int i = 1; i < ac; i++)
	{
		std::string tmp = av[i];
		check_args(tmp);
		input += tmp + (i == ac - 1 ? "" : " ");
	}
	std::cout << "Before:\t" << input << std::endl;
	std::vector<double> vec;
	fill_vector(vec, input);
	sort_vector(vec);
	for(std::vector<double>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << "\n";
	return 0;
}
