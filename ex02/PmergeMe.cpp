/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:33:22 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/27 16:50:49 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int p = 0;

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

void sort_peers(std::vector<std::vector<int> > &v)
{
	size_t i;
	for (i = 0; i < v.size() - 1; i++)
	{
		if(v[i][1] > v[i + 1][1])
		{
			std::swap(v[i], v[i + 1]);
			i = 0;
		}
	}
}

void merge_peers(std::vector<std::vector<int> > &v)
{
	if(v.size() == 1)
		return;
    for (size_t i = 0; i < v.size() - 1; i += 2)
	{
		if(i + 1 > v.size())
			break;
		std::merge(v[i].begin(), v[i].end(), v[i + 1].begin(), v[i + 1].end(), v[i].begin());
		v.erase(v.begin() + i + 1);
	}
	merge_peers(v);
}


void ford_insertion_sort(std::vector<int> &max_peers,std::vector<int> &small_peers)
{
	
}

void sort_vector(std::vector<int> &v)
{
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
		if(vec[i][0] > vec[i][1])
			std::swap(vec[i][0], vec[i][1]);
	}
	sort_peers(vec);
	std::vector<int> res;
	std::vector<int> small_peers;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if(i == 0)
			res.push_back(vec[i][0]);
		res.push_back(vec[i][1]);
		if(i != 0)
			small_peers.push_back(vec[i][0]);
	}
	ford_insertion_sort(res, small_peers);
	v = res;
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
