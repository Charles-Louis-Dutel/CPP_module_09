/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:08:16 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/21 16:58:49 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: this program should be used like : ./PmergeMe int int int int..." << std::endl;
		return (1);
	}

	PmergeMe	sorting;
	std::vector<int>	vec;
	std::vector<int>::iterator	it;

	try
	{
		::init_container(vec, argv);
		std::cout << "Before: ";
		::display_container(vec);
		sorting.merge_sort_vector(vec, 1);
		std::cout << "After: ";
		::display_container(vec);
		std::cout << std::endl << std::endl;
		::is_container_sorted(vec);
	}
	catch (PmergeMe::InvalidArgException	&e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
