/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:12:23 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/20 18:34:16 by cdutel           ###   ########.fr       */
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
static int	max = 0;
void	PmergeMe::merge_sort_vector(std::vector<int> &vec, int pair_lvl)
{
	/*Merging part*/
	typedef std::vector<int>::iterator	Iterator;

	int	possible_pairs = vec.size() / pair_lvl;
	if (possible_pairs < 2)
	{
		std::cout << "\033[31mStarting insert part\033[0m" << std::endl;
		return;
	}
	max = pair_lvl;

	bool		is_odds = 0;
	if (possible_pairs % 2 == 1)
		is_odds = 1;
	int			necessary = (possible_pairs / 2) * pair_lvl * 2;
	std::cout << "possible: " << possible_pairs / 2 << std::endl;
	std::cout << "necessary: " << necessary << std::endl;
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


	/*Inserting part*/
	if (pair_lvl == max)
		return;
	std::cout << "pair lvl: " << pair_lvl << std::endl;
	std::cout << "necessary: " << necessary << std::endl;

	std::vector<int>	main;
	std::vector<int>	pend;
	std::vector<int>	odds;

	start = vec.begin();
	end = start + necessary - 1;

	main.insert(main.begin(), start, start + pair_lvl * 2);
	start += pair_lvl * 2;
	for (int init = pair_lvl * 2; init < necessary; init += pair_lvl * 2)
	{
		pend.insert(pend.begin(), start, start + pair_lvl);
		start += pair_lvl;
		main.insert(main.end(), start, start + pair_lvl);
		start += pair_lvl;
	}
	if (is_odds == 1)
		odds.insert(odds.begin(), start, start + pair_lvl);

	
	// std::cout << "Pend vector: " << std::endl;
	// for (Iterator it = pend.begin(); it != pend.end(); it++)
	// 	std::cout << *it << "\t";
	// std::cout << std::endl;
	// std::cout << "Main vector: " << std::endl;
	// for (Iterator it = main.begin(); it != main.end(); it++)
	// 	std::cout << *it << "\t";
	// std::cout << std::endl;
	// std::cout << "Odds vector: " << std::endl;
	// for (Iterator it = odds.begin(); it != odds.end(); it++)
	// 	std::cout << *it << "\t";
	// std::cout << std::endl << std::endl;
}
