/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:33:25 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/26 15:49:48 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <list>
# include <sstream>
# include<ctime>

void check_args(std::string input);
void fill_vector(std::vector<int> &v, std::string input);
void fill_list(std::list<int> &l, std::string input);
void sort_vector(std::vector<int> &v);
void sort_list(std::list<int> &l);

template <typename T>
void insertion_sort(T &v)
{
	int tmp;
	for (size_t i = 1; i < v.size(); i++)
	{
		tmp = v.at(i);
		int j = i - 1;
		while(j >= 0 && v.at(j) > tmp)
		{
			v.at(j + 1) = v.at(j);
			j--;
		}
		v.at(j + 1) = tmp;
	}
}

#endif
