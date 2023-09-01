/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:21:54 by mkhairou          #+#    #+#             */
/*   Updated: 2023/09/01 11:01:05 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <stack>

class RPN
{
private:
	void CheckInput(std::string tmp);
	std::stack<float> _stack;
	std::string _input;
public:
	void readInput(std::string input);
	void calculate();
	RPN(RPN const &cpy);
	RPN &operator=(RPN const &cpy);
	RPN(/* args */);
	~RPN();
};



#endif
