/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:12:23 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/21 16:37:18 by cdutel           ###   ########.fr       */
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


static void	get_next_jacob(int &prev_jacob, int &curr_jacob)
{
	long	jac;

	jac = prev_jacob * 2 + curr_jacob;
	if (jac > std::numeric_limits<int>::max())
	{
		curr_jacob = std::numeric_limits<int>::max();
		return;
	}
	prev_jacob = curr_jacob;
	curr_jacob = static_cast<int> (jac);
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
		// std::cout << "\033[31mStarting insert part\033[0m" << std::endl;
		return;
	}
	max = pair_lvl;

	bool		is_odds = 0;
	if (possible_pairs % 2 == 1)
		is_odds = 1;
	int			necessary = (possible_pairs / 2) * pair_lvl * 2;
	// std::cout << "possible: " << possible_pairs / 2 << std::endl;
	// std::cout << "necessary: " << necessary << std::endl;
	Iterator	start = vec.begin();
	Iterator	end = start + necessary - 1;
	// std::cout << "end: " << *end << std::endl;

	// std::cout << "pair lvl : " << pair_lvl << std::endl;
	for (Iterator it = vec.begin(); it != end + 1; std::advance(it, pair_lvl * 2))
	{
		//std::cout << "it + pair_lvl - 1: " << *(it + pair_lvl - 1) << " and it + pair_lvl * 2 - 1: " << *(it + pair_lvl * 2 - 1) << std::endl;
		if (*(it + pair_lvl - 1) > *(it + pair_lvl * 2 - 1))
			std::swap_ranges(it, it + pair_lvl, it + pair_lvl);
		//std::iter_swap(it, it + pair_lvl);
	}
	// std::cout << "After pair_lvl " << pair_lvl << " swap : " << std::endl;
	// for (Iterator it2 = vec.begin(); it2 != vec.end(); it2++)
	// {
	// 	std::cout << *it2 << "\t";
	// }
	// std::cout << std::endl << std::endl;
	PmergeMe::merge_sort_vector(vec, pair_lvl * 2);


	/*Inserting part*/
	// std::cout << "\033[31m*******************************************************************************************************\033[0m" << std::endl;
	// std::cout << "\033[34mPAIR_LVL: " << pair_lvl << "\033[0m" << std::endl;
	// std::cout << "necessary: " << necessary << std::endl;

	std::vector<int>	main;
	std::vector<int>	pend;
	std::vector<int>	odds;

	start = vec.begin();
	end = start + necessary - 1;

	main.insert(main.begin(), start, start + pair_lvl * 2);
	start += pair_lvl * 2;
	for (int init = pair_lvl * 2; init < necessary; init += pair_lvl * 2)
	{
		pend.insert(pend.end(), start, start + pair_lvl);
		start += pair_lvl;
		main.insert(main.end(), start, start + pair_lvl);
		start += pair_lvl;
	}
	if (is_odds == 1)
		odds.insert(odds.begin(), start, start + pair_lvl);

	// std::cout << "vec: " << std::endl;
	// for (Iterator it = vec.begin(); it != vec.end(); it++)
	// 	std::cout << *it << "\t";
	// std::cout << std::endl;
	// std::cout << "Pend vector: " << std::endl;
	// for (Iterator it = pend.begin(); it != pend.end(); it++)
	// 	std::cout << *it << "\t";
	// std::cout << std::endl;
	// std::cout << "Main vector: " << std::endl;
	// for (Iterator it = main.begin(); it != main.end(); it++)
	// 	std::cout << *it << "\t";
	// std::cout << std::endl;
	// if (!odds.empty())
	// {
	// 	std::cout << "Odds vector: " << std::endl;
	// 	for (Iterator it = odds.begin(); it != odds.end(); it++)
	// 		std::cout << *it << "\t";
	// 	std::cout << std::endl << std::endl;
	// }
	// std::cout << std::endl << std::endl;

	int	pend_size = pend.size();
	int	curr_jacob = 1;
	int	prev_jacob = 1;
	int	to_insert;
	Iterator	main_start = main.begin();
	Iterator	main_end = main.end();
	Iterator	pend_start = pend.begin();
	while (pend_size > 0)
	{
		get_next_jacob(prev_jacob, curr_jacob);
		to_insert = curr_jacob - prev_jacob;
		if (to_insert > pend_size / pair_lvl)
		{
			// std::cout << "\033[32mWITHOUT JACOB\033[0m" << std::endl;
			main_start = main.begin();
			main_end = main.end();
			pend_start = pend.begin();
			for (; main_start != main_end; main_start += pair_lvl)
			{
				// std::cout << "main : " << *(main_start + pair_lvl - 1) << "\tpend :" << *(pend_start + pair_lvl - 1) << std::endl;
				if (*(main_start + pair_lvl - 1) > *(pend_start + pair_lvl - 1))
				{
					main.insert(main_start, pend_start, pend_start + pair_lvl);
					pend.erase(pend_start, pend_start + pair_lvl);
					break;
				}
				if (main_start + pair_lvl == main_end)
				{
					main.insert(main.end(), pend_start + (to_insert - 1) * pair_lvl, pend_start + ((to_insert - 1) * pair_lvl) + pair_lvl - 1);
					pend.erase(pend_start + (to_insert - 1) * pair_lvl, pend_start + ((to_insert - 1) * pair_lvl) + pair_lvl - 1);
					break;
				}
				//main_start += pair_lvl;
			}
			pend_size -= pair_lvl;
			// std::cout << "Main vector: " << std::endl;
			// for (Iterator it = main.begin(); it != main.end(); it++)
			// 	std::cout << *it << "\t";
			// std::cout << std::endl;
		}
		else
		{
			// std::cout << "\033[33mWITH JACOB\033[0m" << std::endl;
			while (to_insert > 0 && pend_size > 0)
			{
				main_start = main.begin();
				main_end = main.end();
				pend_start = pend.begin();
				// std::cout << "to_insert: " << to_insert << std::endl;
				// std::cout << "\tmain : " << *(main_start + pair_lvl - 1) << "\tpend :" << *(pend_start + ((to_insert - 1) * pair_lvl) + pair_lvl - 1) << std::endl;
				for (; main_start != main_end; main_start += pair_lvl)
				{
					// std::cout << "main : " << *(main_start + pair_lvl - 1) << "\tpend :" << *(pend_start + ((to_insert - 1) * pair_lvl) + pair_lvl - 1) << std::endl;
					if (*(main_start + pair_lvl - 1) > *(pend_start + ((to_insert - 1) * pair_lvl) + pair_lvl - 1))
					{
						main.insert(main_start, pend_start + (to_insert - 1) * pair_lvl, pend_start + ((to_insert - 1) * pair_lvl) + pair_lvl);
						pend.erase(pend_start + (to_insert - 1) * pair_lvl, pend_start + ((to_insert - 1) * pair_lvl) + pair_lvl);
						break;
					}
					if (main_start + pair_lvl == main_end)
					{
						main.insert(main.end(), pend_start + (to_insert - 1) * pair_lvl, pend_start + ((to_insert - 1) * pair_lvl) + pair_lvl);
						pend.erase(pend_start + (to_insert - 1) * pair_lvl, pend_start + ((to_insert - 1) * pair_lvl) + pair_lvl);
						break;
					}
					//main_start += pair_lvl;
				}
				pend_size -= pair_lvl;
				to_insert--;

				// std::cout << "Pend vector: " << std::endl;
				// for (Iterator it = pend.begin(); it != pend.end(); it++)
				// 	std::cout << *it << "\t";
				// std::cout << std::endl;
				// std::cout << "Main vector: " << std::endl;
				// for (Iterator it = main.begin(); it != main.end(); it++)
				// 	std::cout << *it << "\t";
				// std::cout << std::endl;
			}
		}
	}
	// std::cout << "Main vector with pend added: " << std::endl;
	// for (Iterator it = main.begin(); it != main.end(); it++)
	// 	std::cout << *it << "\t";
	// std::cout << std::endl;
	if (!odds.empty())
	{
		// std::cout << "ODDSSSSSSSSSSSS" << std::endl;
		main_start = main.begin();
		main_end = main.end();
		for (; main_start != main_end; main_start += pair_lvl)
		{
			//std::cout << "main : " << *(main_start + pair_lvl - 1) << "\tpend :" << *(pend_start + pair_lvl - 1) << std::endl;
			if (*(main_start + pair_lvl - 1) > *(odds.begin() + pair_lvl - 1))
			{
				main.insert(main_start, odds.begin(), odds.begin() + pair_lvl);
				odds.erase(odds.begin(), odds.begin() + pair_lvl);
				break;
			}
			if (main_start + pair_lvl == main_end)
			{
				main.insert(main.end(), odds.begin(), odds.begin() + pair_lvl);
				odds.erase(odds.begin(), odds.begin() + pair_lvl);
				break;
			}
			//main_start += pair_lvl;
		}
	}
	// std::cout << "Main vector after all insert: " << std::endl;
	// for (Iterator it = main.begin(); it != main.end(); it++)
	// 	std::cout << *it << "\t";
	// std::cout << std::endl;

	vec.erase(vec.begin(), vec.begin() + main.size());
	vec.insert(vec.begin(), main.begin(), main.end());

	// std::cout << "Vec after all insert: " << std::endl;
	// for (Iterator it = vec.begin(); it != vec.end(); it++)
	// 	std::cout << *it << "\t";
	// std::cout << std::endl;


	// std::cout << std::endl << std::endl;
}
