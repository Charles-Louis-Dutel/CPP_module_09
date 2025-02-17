/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:09:10 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/17 17:17:15 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const &inst);

	private:
		std::vector<int>	_vec;
		std::deque<int>		_queue;
		unsigned int		_start_time;
};

#endif
