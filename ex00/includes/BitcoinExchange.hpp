/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:56:00 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/17 13:32:27 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <utility>
# include <cstdlib>

# define DATA "data.csv"

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(BitcoinExchange const &inst);

		void			proceed_calc(std::string inf_name);

	private:
		std::map<std::string, float>	_database;

		bool	_init_database(void);
		void	_print_value(std::string inf_date, float inf_value);
};

#endif
