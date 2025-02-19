/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:09:10 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/19 02:08:26 by cdutel           ###   ########.fr       */
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

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(char **argv);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const &inst);

		class	InvalidArgumentsException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Invalid arguments list";
				}
		};

	private:
		std::vector<int>	_vec;
		std::deque<int>		_queue;
		unsigned int		_start_time;

		void				init_containers(char **argv);
};

#endif
