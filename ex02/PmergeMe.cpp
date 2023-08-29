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

void sort_peers(std::vector<std::vector<int> > &v, size_t i = 0) {
    if (i == v.size() - 1)
        return;
    else
	{
        if (v[i][1] > v[i + 1][1])
		{
            std::swap(v[i], v[i + 1]);
            sort_peers(v, 0);
        }
        else
            sort_peers(v, i + 1);
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

int jacobstal_number(int n)
{
	return (std::pow(2, n) - std::pow(-1, n)) / 3;
}

void ford_insertion_sort(std::vector<int> &max_peers,std::vector<int> &small_peers)
{
	std::vector<int> jac;
	std::vector<int>::iterator it = std::upper_bound(max_peers.begin(), max_peers.end(), small_peers[1]);
	max_peers.insert(it, small_peers[1]);
	for (size_t i = 2; i < small_peers.size(); i++)
	{
		jac.push_back(jacobstal_number(i));
	}
	bool stop = false;
	for (size_t i = 1; i < jac.size(); i++)
	{		
		if(jac[i] >= (int)small_peers.size())
		{
			jac[i] = small_peers.size() - 1;
			stop = true;
		}

		for (int j = jac[i]; j > jac[i - 1]; j--) 
		{
			std::vector<int>::iterator it = std::upper_bound(max_peers.begin(), max_peers.end(), small_peers[j]);
			max_peers.insert(it, small_peers[j]);
		}
		if(stop)
			break;
	}
}

void sort_vector(std::vector<int> &v)
{
	std::vector<std::vector<int> > vec;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it += 2)
	{
		std::vector<int> tmp;
		tmp.push_back(*it);
		tmp.push_back(*(it + 1));
		vec.push_back(tmp);
	}
	for (std::vector<std::vector<int> >::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if(it[0][0] > it[0][1])
			std::swap(it[0][0], it[0][1]);
	}
	sort_peers(vec);
	std::vector<int> res;
	std::vector<int> small_peers;
	for (std::vector<std::vector<int> >::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if(it == vec.begin())
			res.push_back(it[0][0]);
		res.push_back(it[0][1]);
		small_peers.push_back(it[0][0]);
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
