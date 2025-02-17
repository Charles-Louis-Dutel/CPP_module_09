/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:08:16 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/17 17:22:46 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: this program should be used like : ./PmergeMe int int int int..." << std::endl;
		return (1);
	}
	return (0);
}
