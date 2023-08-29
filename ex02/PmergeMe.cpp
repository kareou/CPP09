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

void sort_peers(std::vector<std::vector<int> > &v, size_t start = 0) {
    bool swapped = false;
    for (size_t i = start; i < v.size() - 1; i++) {
        if (v[i][1] > v[i + 1][1]) {
            std::swap(v[i], v[i + 1]);
            swapped = true;
        }
    }
    // only recurse if a swap occurred in the last pass
    if (swapped) {
        sort_peers(v);
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
	int trashhold = -1;
	if(v.size() == 1)
		return;
	if(v.size() % 2 != 0)
	{
		trashhold = v[v.size() - 1];
		v.pop_back();
	}

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
	if(trashhold != -1)
	{
		std::vector<int>::iterator it = std::upper_bound(v.begin(), v.end(), trashhold);
		v.insert(it, trashhold);
	}
}

void insertion_sort_l(std::list<int> &l, std::list<int> &small_peers)
{
	std::list<int>::iterator it = small_peers.begin();
	std::advance(it, 1);
	std::list<int>::iterator it2 = std::upper_bound(l.begin(), l.end(), *it);
	l.insert(it2, *it);

	std::vector<int> jac;
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
			std::list<int>::iterator it_tmp = small_peers.begin();
			std::advance(it_tmp, j);
			std::list<int>::iterator it = std::upper_bound(l.begin(), l.end(), *it_tmp);
			l.insert(it, *it_tmp);
		}
		if(stop)
			break;
	}

}

void sort_list(std::list<int> &l)
{
	int trashhold = -1;

	if(l.size() == 1)
		return;
	if(l.size() % 2 != 0)
	{
		std::list<int>::iterator it = l.begin();
		std::advance(it, l.size() - 1);
		trashhold = *it;
		l.erase(it);
	}
	std::list<std::list<int> > list;
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		std::list<int> tmp;
		tmp.push_back(*it);
		tmp.push_back(*(++it));
		list.push_back(tmp);
	}
	//sort each pair
	for (std::list<std::list<int> >::iterator it = list.begin(); it != list.end(); it++)
	{
		if(it->front() > it->back())
			std::swap(it->front(), it->back());
	}
	//sort the pairs
	list.sort();
	//merge the pairs
	std::list<int> res;
	std::list<int> small_peers;
	for (std::list<std::list<int> >::iterator it = list.begin(); it != list.end(); it++)
	{
		if(it == list.begin())
			res.push_back(it->front());
		res.push_back(it->back());
		small_peers.push_back(it->front());
	}
	//insertion sort
	insertion_sort_l(res, small_peers);
	l = res;
	if(trashhold != -1)
	{
		std::list<int>::iterator it = std::upper_bound(l.begin(), l.end(), trashhold);
		l.insert(it, trashhold);
	}
	
}
