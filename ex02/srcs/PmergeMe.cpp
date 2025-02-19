/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:12:23 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/19 02:28:00 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _vec(), _queue()
{
}

PmergeMe::PmergeMe(char **argv)
{
	try
	{
		this->init_containers(argv);
	}
	catch(PmergeMe::InvalidArgumentsException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Error" << std::endl;
	}
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe(void)
{
}


/*Operator overload*/
PmergeMe	&PmergeMe::operator=(PmergeMe const &inst)
{
	if (this != &inst)
	{
		this->_vec = inst._vec;
		this->_queue = inst._queue;
		this->_start_time = inst._start_time;
	}
	return (*this);
}


/*Private member functions*/
void	PmergeMe::init_containers(char **argv)
{
	long		n;
	std::string	temp;

	for (int i = 1; argv[i]; i++)
	{
		temp = argv[i];
		if (temp.size() > 10 || temp.find_first_not_of("0123456789") != std::string::npos)
			throw PmergeMe::InvalidArgumentsException();
		n = std::atol(argv[i]);
		if (n < 0 || n > std::numeric_limits<int>::max())
			throw PmergeMe::InvalidArgumentsException();
		this->_queue.push_back(static_cast<int>(n));
		this->_vec.push_back(static_cast<int>(n));
	}
}
