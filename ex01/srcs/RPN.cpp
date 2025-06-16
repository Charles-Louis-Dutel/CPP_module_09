/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:42:46 by cdutel            #+#    #+#             */
/*   Updated: 2025/06/16 15:24:10 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(RPN const &copy)
{
	*this = copy;
}

RPN::~RPN(void)
{
}


/*Operator overload*/
RPN	&RPN::operator=(RPN const &inst)
{
	if (this != &inst)
	{
		this->_mystack = inst._mystack;
	}
	return (*this);
}


/*Non member functions*/
static bool	is_sign(char c)
{
	if (c != '+'&& c != '-' && c != '*' && c != '/')
		return (0);
	return (1);
}

static bool	is_num(char c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

static int	calc(int n1, int n2, char c)
{
	int res;
	switch (c)
	{
		case '+':
			res = n2 + n1;
			break;
		case '-':
			res = n2 - n1;
			break;
		case '*':
			res = n2 * n1;
			break;
		case '/':
			if (n2 == 0)
				throw RPN::DivideByZeroException();
			res = n2 / n1;
			break;
		default:
			throw RPN::BadInputException();
	}
	return (res);
}

/*Public member functions*/
void	RPN::proceed_calc(std::string input)
{
	int	i = 0;
	int	num = 0;
	int	num2 = 0;
	int	res = 0;
	int	space = 0;

	while (input[i])
	{
		if (i == 0 && !is_num(input[i]))
			throw RPN::BadInputException();
		if (is_num(input[i]))
		{
			num = std::atoi(&input[i]);
			if (num < 0 || num > 9)
				throw RPN::BadInputException();
			this->_mystack.push(num);
			space = 0;
		}
		else if (is_sign(input[i]) && space == 1)
		{
			if (this->_mystack.empty())
				throw RPN::BadInputException();
			num = this->_mystack.top();
			this->_mystack.pop();

			if (this->_mystack.empty())
				throw RPN::BadInputException();
			num2 = this->_mystack.top();
			this->_mystack.pop();

			res = calc(num, num2, input[i]);
			this->_mystack.push(res);
			space = 0;
		}
		else if (input[i] == ' ' && space == 0)
			space = 1;
		else
			throw RPN::BadInputException();
		i++;
	}
	if (this->_mystack.empty() || this->_mystack.size() != 1)
		throw RPN::BadInputException();
	std::cout << this->_mystack.top() << std::endl;
}
