/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:33:15 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/27 13:05:18 by mkhairou         ###   ########.fr       */
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
	std::vector<int> vec;
	std::list<int> list;
    clock_t vstart = clock();
	fill_vector(vec, input);
	sort_vector(vec);
    clock_t vend = clock();
    clock_t lstart = clock();
	fill_list(list, input);
	sort_list(list);
    clock_t lend = clock();
	std::cout << "After:\t";
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << (it + 1 == vec.end() ? "\n" : " ");
	 double vtimer = static_cast<double>(vend - vstart);
	 double ltimer = static_cast<double>(lend - lstart);
	std::cout << "Time to process a range of "<< vec.size() <<" elements with std::vector " << vtimer  << "us\n";
	std::cout << "Time to process a range of "<< list.size() <<" elements with std::vector " << ltimer << "us\n";
	return 0;
}
