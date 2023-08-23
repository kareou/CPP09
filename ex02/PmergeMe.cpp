/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:33:22 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/23 16:51:07 by mkhairou         ###   ########.fr       */
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

void fill_vector(std::vector<double> &v, std::string input)
{
	std::stringstream ss(input);
	std::string tmp;
	while(ss >> tmp)
	{
		v.push_back(std::strtod(tmp.c_str(),NULL));
	}
}

void sort_vector(std::vector<double> &v)
{

	double tmp = -1;
	if(v.size() % 2 != 0)
	{
		tmp = v.back();
		v.pop_back();
		// tmp = *it;
	}
	std::vector<std::vector<double> > vec;
	for (size_t i = 0; i < v.size(); i += 2)
	{
		std::vector<double> tmp;
		tmp.push_back(v[i]);
		tmp.push_back(v[i + 1]);
		vec.push_back(tmp);
	}
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::sort(vec[i].begin(), vec[i].end());
	}
	std::sort(vec.begin(), vec.end());
	std::vector<double> res;
	for (size_t i = 0; i < vec.size(); i++)
	{
		res.push_back(vec[i][1]);
	}
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::vector<double>::iterator place = std::lower_bound(res.begin(), res.end(), vec[i][0]);
		res.insert(place, vec[i][0]);
	}
	if(tmp != -1)
	{
		std::vector<double>::iterator place = std::lower_bound(res.begin(), res.end(), tmp);
		res.insert(place, tmp);
	}
	v = res;
}
