/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:08:16 by cdutel            #+#    #+#             */
/*   Updated: 2025/06/16 18:39:31 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iomanip>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: this program should be used like : ./PmergeMe int int int int..." << std::endl;
		return (1);
	}

	PmergeMe	sorting;
	clock_t		start_time;
	clock_t		end_time;
	double		computing_time;

	try
	{
		std::vector<int>	vec;
		//std::vector<int>::iterator	it;

		start_time = std::clock();
		::init_container(vec, argv);
		std::cout << "Before: ";
		::display_container(vec);

		sorting.merge_sort_vector(vec, 1);
		end_time = std::clock();

		std::cout << "After: ";
		::display_container(vec);
		::is_container_sorted(vec);

		computing_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << vec.size();
		std::cout << " elements with std::vector : " << std::fixed << std::setprecision(5);
		std::cout << computing_time << "us" << std::endl;


		//std::cout << std::endl << std::endl << std::endl;


		std::deque<int>	deq;
		//std::deque<int>::iterator	it_deq;

		start_time = std::clock();
		::init_container(deq, argv);
		//std::cout << "Before: ";
		//::display_container(deq);

		sorting.merge_sort_deque(deq, 1);
		end_time = std::clock();

		//std::cout << "After: ";
		//::display_container(deq);
		//::is_container_sorted(deq);

		computing_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << deq.size();
		std::cout << " elements with std::deque : " << std::fixed << std::setprecision(5);
		std::cout << computing_time << "us" << std::endl;
	}
	catch (PmergeMe::InvalidArgException	&e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
