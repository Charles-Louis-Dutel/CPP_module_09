/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:09:10 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/21 17:30:07 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <stdexcept>
# include <limits>
# include <cstdlib>
# include <algorithm>

# define MAX_SIZE 10000

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const &inst);

		void		merge_sort_vector(std::vector<int> &vec, int pair_lvl);
		void		merge_sort_deque(std::deque<int> &deq, int pair_lvl);

		class InvalidArgException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Error: List of arguments is invalid";
				}
		};

	private:
		unsigned int		_start_time;
};

template<typename T>
void	init_container(T &cont, char **argv)
{
	long		n;
	std::string	temp;

	for (int i = 1; argv[i]; i++)
	{
		temp = argv[i];
		if (i > MAX_SIZE)
			throw PmergeMe::InvalidArgException();
		if (temp.size() > 10 || temp.find_first_not_of("0123456789") != std::string::npos)
			throw PmergeMe::InvalidArgException();
		n = std::atol(argv[i]);
		if (n < 0 || n > std::numeric_limits<int>::max())
			throw PmergeMe::InvalidArgException();
		cont.push_back(static_cast<int>(n));
	}
}

template<typename T>
void	is_container_sorted(T &cont)
{
	for (size_t i = 1; i < cont.size(); i++)
	{
		if (cont[i] < cont[i - 1])
		{
			std::cout << "NOT SORTED" << std::endl;
			return;
		}
	}
	std::cout << "Container is successfully sorted !" << std::endl;
}

template<typename T>
void	display_container(T &cont)
{
	for (size_t i = 0; i < cont.size(); i++)
	{
		std::cout << cont[i];
		if (i + 1 != cont.size())
			std::cout << "  ";
	}
	std::cout << std::endl;
}
#endif
