/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:08:16 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/21 15:19:37 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

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

	::init_container(vec, argv);
	std::cout << "Before trying to swap : " << std::endl;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl << std::endl << std::endl;

	sorting.merge_sort_vector(vec, 1);

	// Vérification finale pour repositionner le dernier élément s'il n'est pas le plus grand


	std::cout << std::endl << std::endl << "After last swap : " << std::endl;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

	return (0);
}
