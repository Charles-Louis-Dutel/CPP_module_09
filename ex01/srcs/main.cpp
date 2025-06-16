/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:37:54 by cdutel            #+#    #+#             */
/*   Updated: 2025/06/16 15:24:58 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: this program should be used like : ./RPN \"arg\"" << std::endl;
		return (1);
	}
	RPN			calculator;
	std::string	arg = argv[1];

	try
	{
		calculator.proceed_calc(arg);
	}
	catch(RPN::BadInputException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(RPN::DivideByZeroException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
