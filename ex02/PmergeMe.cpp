/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:33:22 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/24 13:52:35 by mkhairou         ###   ########.fr       */
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

	int tmp = -1;
	if(v.size() % 2 != 0)
	{
		tmp = v.back();
		v.pop_back();
	}
	std::vector<std::vector<int> > vec;
	for (size_t i = 0; i < v.size(); i += 2)
	{
		std::vector<int> tmp;
		tmp.push_back(v[i]);
		tmp.push_back(v[i + 1]);
		vec.push_back(tmp);
	}
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::sort(vec[i].begin(), vec[i].end());
	}
	std::sort(vec.begin(), vec.end());
	std::vector<int> res;
	for (size_t i = 0; i < vec.size(); i++)
	{
		res.push_back(vec[i][1]);
	}
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::vector<int>::iterator place = std::lower_bound(res.begin(), res.end(), vec[i][0]);
		res.insert(place, vec[i][0]);
	}
	if(tmp != -1)
	{
		std::vector<int>::iterator place = std::lower_bound(res.begin(), res.end(), tmp);
		res.insert(place, tmp);
	}
	v = res;
}

void sort_list(std::list<int> &l)
{
	int tmp = -1;
	if(l.size() % 2 != 0)
	{
		tmp = l.back();
		l.pop_back();
	}
	std::list<std::list<int> > lis;
	while(!l.empty())
	{
		std::list<int> tmp;
		tmp.push_back(l.front());
		l.pop_front();
		tmp.push_back(l.front());
		l.pop_front();
		lis.push_back(tmp);
	}
	for (std::list<std::list<int> >::iterator it = lis.begin(); it != lis.end(); ++it)
	{
		it->sort();
	}
	lis.sort();
	std::list<int> res;
	for (std::list<std::list<int> >::iterator it = lis.begin(); it != lis.end(); ++it)
	{
		res.push_back(it->back());
	}
	for (std::list<std::list<int> >::iterator it = lis.begin(); it != lis.end(); ++it)
	{
		std::list<int>::iterator place = std::lower_bound(res.begin(), res.end(), it->front());
		res.insert(place, it->front());
	}
	if(tmp != -1)
	{
		std::list<int>::iterator place = std::lower_bound(res.begin(), res.end(), tmp);
		res.insert(place, tmp);
	}
	l = res;
}
