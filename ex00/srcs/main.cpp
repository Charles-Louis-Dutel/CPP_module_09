/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:56:42 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/17 13:48:06 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: this program should be used like : ./btc \"valid_file\"" << std::endl;
		return (1);
	}
	BitcoinExchange	bitcoin_exchanger;
	std::string		infile = argv[1];

	bitcoin_exchanger.proceed_calc(infile);

	return (0);
}
