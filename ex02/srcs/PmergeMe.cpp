/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:12:23 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/17 17:20:40 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
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
}
