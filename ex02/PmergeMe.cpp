/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:33:22 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/26 16:36:45 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	check_args(std::string input)
{
	char	*leftover;
	double	test;

	test = std::strtod(input.c_str(), &leftover);
	if (*leftover != '\0')
	{
		std::cout << "Error\n";
		exit(1);
	}
	if (test < 0)
	{
		std::cout << "Error\n";
		exit(1);
	}
}

void fill_vector(std::vector<int> &v, std::string input)
{
	std::stringstream ss(input);
	std::string tmp;
	while(ss >> tmp)
	{
		v.push_back(std::strtod(tmp.c_str(),NULL));
	}
}

void fill_list(std::list<int> &l, std::string input)
{
	std::stringstream ss(input);
	std::string tmp;
	while(ss >> tmp)
	{
		l.push_back(std::strtod(tmp.c_str(),NULL));
	}
}


void sort_vector(std::vector<int> &v)
{
	if(v.size() <=  12)
	{
		insertion_sort(v);
		return;
	}
	std::vector<int>::iterator mid = v.begin();
	std::advance(mid, v.size() / 2);

	std::vector<int> first_half(v.begin(), mid);
	std::vector<int> second_half(mid, v.end());

	sort_vector(first_half);
	sort_vector(second_half);

	std::merge(first_half.begin(), first_half.end(), second_half.begin(), second_half.end(),v.back());

}

// void sort_list(std::list<int> &l)
// {
// 	if(l.size() >=  14)
// 	{
// 		insertion_sort(l);
// 		return;
// 	}
// 	std::list<int>::iterator mid = l.begin();
// 	std::advance(mid, l.size() / 2);

// 	std::list<int> first_half(l.begin(), mid);
// 	std::list<int> second_half(mid, l.end());

// 	sort_list(first_half);
// 	sort_list(second_half);

// 	std::list<int> res;
// 	std::merge(first_half.begin(), first_half.end(), second_half.begin(), second_half.end(), std::back_inserter(res));
// 	l = res;
// }
