/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:09:10 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/20 11:18:20 by cdutel           ###   ########.fr       */
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

template<typename T>
void	init_container(T &cont, char **argv)
{
	long		n;
	std::string	temp;

	for (int i = 1; argv[i]; i++)
	{
		temp = argv[i];
		if (temp.size() > 10 || temp.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cerr << "List of arguments is invalid" << std::endl;
			return;
		}
		n = std::atol(argv[i]);
		if (n < 0 || n > std::numeric_limits<int>::max())
		{
			std::cerr << "List of arguments is invalid" << std::endl;
			return;
		}
		cont.push_back(static_cast<int>(n));
	}
}

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const &inst);

		void		merge_sort_vector(std::vector<int> &vec, int pair_lvl);

	private:
		unsigned int		_start_time;
};

#endif
