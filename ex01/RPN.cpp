/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:21:52 by mkhairou          #+#    #+#             */
/*   Updated: 2023/08/23 13:50:26 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(/* args */)
{
}

RPN::RPN(RPN const &cpy)
{
	*this = cpy;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(RPN const &cpy)
{
	(void)cpy;
	return (*this);
}


void	RPN::CheckInput(std::string tmp)
{
	if(tmp.length() == 1 && !isdigit(tmp[0]))
	{
		if(tmp[0] != '+' && tmp[0] != '-' && tmp[0] != '*' && tmp[0] != '/')
		{
			std::cout << "Error\n";
			exit(1);
		}
	}
	else if(tmp.length() > 1)
	{
		if(tmp[0] == '+' || tmp[0] == '-')
		{
			if(!isdigit(tmp[1]))
			{
				std::cout << "Error\n";
				exit(1);
			}
		}
		else
		{
			std::cout << "Error\n";
			exit(1);
		}
	}
}

void RPN::readInput(std::string input)
{
	std::stringstream ss(input);
	std::string tmp;
	while (ss >> tmp)
	{
		CheckInput(tmp);
	}
	_input = input;
}

void RPN::calculate()
{
	std::stringstream ss(_input);
	std::string tmp;
	float a, b;
	while(ss >> tmp)
	{
		if(std::isdigit(tmp[0]))
		{
			_stack.push(std::atof(tmp.c_str()));
		}
		else if(tmp[0] == '+')
		{
			if(_stack.size() < 2)
			{
				std::cout << "Error\n";
				exit(1);
			}
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_stack.push(a + b);
		}
		else if(tmp[0] == '-')
		{
			if(_stack.size() < 2)
			{
				std::cout << "Error\n";
				exit(1);
			}
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_stack.push(b - a);
		}
		else if(tmp[0] == '*')
		{
			if(_stack.size() < 2)
			{
				std::cout << "Error\n";
				exit(1);
			}
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_stack.push(a * b);
		}
		else if(tmp[0] == '/')
		{
			if(_stack.size() < 2)
			{
				std::cout << "Error\n";
				exit(1);
			}
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_stack.push(b / a);
		}
	}
	if(_stack.size() != 1)
	{
		std::cout << "Error\n";
		exit(1);
	}
	std::cout << _stack.top() << std::endl;
}
