/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:12:23 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/20 16:30:27 by cdutel           ###   ########.fr       */
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
		this->_start_time = inst._start_time;
	}
	return (*this);
}


/*Public member functions*/
void	PmergeMe::merge_sort_vector(std::vector<int> &vec, int pair_lvl)
{
	typedef std::vector<int>::iterator	Iterator;

	int	possible_pairs = vec.size() / pair_lvl;
	if (possible_pairs < 2)
		return;

	int			necessary = (possible_pairs / 2) * pair_lvl * 2;
	// std::cout << "possible: " << possible_pairs / 2 << std::endl;
	// std::cout << "necessary: " << necessary << std::endl;
	Iterator	start = vec.begin();
	Iterator	end = start + necessary - 1;
	// std::cout << "end: " << *end << std::endl;

	std::cout << "pair lvl : " << pair_lvl << std::endl;
	for (Iterator it = vec.begin(); it != end + 1; std::advance(it, pair_lvl * 2))
	{
		//std::cout << "it + pair_lvl - 1: " << *(it + pair_lvl - 1) << " and it + pair_lvl * 2 - 1: " << *(it + pair_lvl * 2 - 1) << std::endl;
		if (*(it + pair_lvl - 1) > *(it + pair_lvl * 2 - 1))
			std::swap_ranges(it, it + pair_lvl, it + pair_lvl);
		//std::iter_swap(it, it + pair_lvl);
	}
	std::cout << "After pair_lvl " << pair_lvl << " swap : " << std::endl;
	for (Iterator it2 = vec.begin(); it2 != vec.end(); it2++)
	{
		std::cout << *it2 << "\t";
	}
	std::cout << std::endl << std::endl;
	PmergeMe::merge_sort_vector(vec, pair_lvl * 2);
}
