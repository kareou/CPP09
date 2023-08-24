/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:33:25 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/24 12:58:54 by mkhairou         ###   ########.fr       */
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

#endif
